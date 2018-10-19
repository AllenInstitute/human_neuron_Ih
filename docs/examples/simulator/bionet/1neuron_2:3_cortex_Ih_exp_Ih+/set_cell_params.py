import json
from bmtk.simulator.bionet.nrn import *
from neuron import h
import numpy as np

@cell_model
def IntFire1(cell_prop):
    """Loads a point integrate and fire neuron"""
    model_params = cell_prop.model_params
    hobj = h.IntFire1()
    hobj.tau = model_params['tau']*1000.0  # Convert from seconds to ms.
    hobj.refrac = model_params['refrac']*1000.0  # Convert from seconds to ms.
    return hobj

@cell_model
def Biophys1(cell_prop):
    '''
    Set parameters for cells from the Allen Cell Types database
    Prior to setting parameters will replace the axon with the stub

    '''

    morphology_file_name = str(cell_prop['morphology_file'])
    hobj = h.Biophys1(morphology_file_name)
    fix_axon_allactive(hobj)
    #fix_axon(hobj)
    # set_params_peri(hobj, cell_prop.model_params)
    set_params(hobj, cell_prop.model_params)

    def calc_density_exp(dist):
        # FILL IN HERE
        g_max=2.84922026765e-07
        density=g_max*(-0.8696 + 2.087*np.exp((dist)*0.0031))
        #return dist
        return density

    targeted_sections = ['apic']  # only apply to these types of segements
    h.distance(sec=hobj.soma[0])   # need this to set all distances relative to soma (not sure if from center?)
    for sec in hobj.all:
        sec_type = sec.name().split(".")[1][:4]
        if sec_type in targeted_sections:
            # sec.insert('Ih_mod')  # insert channel mechanics
            for seg in sec:
                dist = h.distance(seg.x)
                sec_density = calc_density_exp(dist)  # calculate the channel density
                setattr(seg, 'gbar_Ih_mod', sec_density)  # 0.0166428509042) 

    for sec in hobj.all:
        sec_type = sec.name().split(".")[1][:4]
        if sec_type == 'axon':
            continue

# print the distance!

        #if sec_type in targeted_sections:
        print sec.name()
        for seg in sec:
            print h.distance(seg.x), seg.gbar_Ih_mod

    return hobj


def set_params_peri(hobj, biophys_params):
    """Set biophysical parameters for the cell"""
    passive = biophys_params['passive'][0]
    conditions = biophys_params['conditions'][0]
    genome = biophys_params['genome']

    # Set passive properties
    cm_dict = dict([(c['section'], c['cm']) for c in passive['cm']])
    for sec in hobj.all:
        sec.Ra = passive['ra']
        sec.cm = cm_dict[sec.name().split(".")[1][:4]]
        sec.insert('pas')

        for seg in sec:
            seg.pas.e = passive["e_pas"]

    # Insert channels and set parameters

    for p in genome:
        sections = [s for s in hobj.all if s.name().split(".")[1][:4] == p["section"]]

        for sec in sections:
            #            print p
            if p["mechanism"] != "":
                sec.insert(p["mechanism"])
            setattr(sec, p["name"], p["value"])

    # Set reversal potentials
    for erev in conditions['erev']:
        sections = [s for s in hobj.all if s.name().split(".")[1][:4] == erev["section"]]
        for sec in sections:
            sec.ena = erev["ena"]
            sec.ek = erev["ek"]


def fix_axon(hobj):
    """Replace reconstructed axon with a stub

    Parameters
    ----------
    hobj: instance of a Biophysical template
        NEURON's cell object
    """
    for sec in hobj.axon:
        h.delete_section(sec=sec)

    h.execute('create axon[2]', hobj)

    for sec in hobj.axon:
        sec.L = 30
        sec.diam = 1
        hobj.axonal.append(sec=sec)
        hobj.all.append(sec=sec)  # need to remove this comment

    hobj.axon[0].connect(hobj.soma[0], 0.5, 0)
    hobj.axon[1].connect(hobj.axon[0], 1, 0)

    h.define_shape()

def set_params(hobj, params_dict):
    # params_dict = json.load(open(params_file_name, 'r'))
    passive = params_dict['passive'][0]
    genome = params_dict['genome']
    conditions = params_dict['conditions'][0]

    section_map = {}
    for sec in hobj.all:
        section_name = sec.name().split(".")[1][:4]
        if section_name in section_map:
            section_map[section_name].append(sec)
        else:
            section_map[section_name] = [sec]

    for sec in hobj.all:
        sec.insert('pas')
        # sec.insert('extracellular')

    if 'e_pas' in passive:
        e_pas_val = passive['e_pas']
        for sec in hobj.all:
            for seg in sec:
                seg.pas.e = e_pas_val

    if 'ra' in passive:
        ra_val = passive['ra']
        for sec in hobj.all:
            sec.Ra = ra_val

    if 'cm' in passive:
        for cm_dict in passive['cm']:
            cm = cm_dict['cm']
            for sec in section_map.get(cm_dict['section'], []):
                sec.cm = cm

    for genome_dict in genome:
        g_section = genome_dict['section']
        if genome_dict['section'] == 'glob':
            print("WARNING: There is a section called glob, probably old json file")
            continue

        g_value = float(genome_dict['value'])
        g_name = genome_dict['name']
        g_mechanism = genome_dict.get("mechanism", "")
        for sec in section_map.get(g_section, []):
            if g_mechanism != "":
                sec.insert(g_mechanism)
            setattr(sec, g_name, g_value)

    for erev in conditions['erev']:
        erev_section = erev['section']
        erev_ena = erev['ena']
        erev_ek = erev['ek']
        if erev_section in section_map:
            for sec in section_map.get(erev_section, []):
                if h.ismembrane('k_ion', sec=sec) == 1:
                    setattr(sec, 'ek', erev_ek)
                if h.ismembrane('na_ion', sec=sec) == 1:
                    setattr(sec, 'ena', erev_ena)
        else:
            print("Warning: can't set erev for {}, section array doesn't exist".format(erev_section))

def fix_axon_allactive(hobj):
    """Replace reconstructed axon with a stub

    Parameters
    ----------
    hobj: instance of a Biophysical template
        NEURON's cell object
    """
    # find the start and end diameter of the original axon, this is different from the perisomatic cell model
    # where diameter == 1.
    axon_diams = [hobj.axon[0].diam, hobj.axon[0].diam]
    for sec in hobj.all:
        section_name = sec.name().split(".")[1][:4]
        if section_name == 'axon':
            axon_diams[1] = sec.diam

    for sec in hobj.axon:
        h.delete_section(sec=sec)

    h.execute('create axon[2]', hobj)
    for index, sec in enumerate(hobj.axon):
        sec.L = 30
        print axon_diams[index]
        sec.diam = axon_diams[index]  # 1

        hobj.axonal.append(sec=sec)
        hobj.all.append(sec=sec)  # need to remove this comment
# original allen sdk: hobj.soma[0], 0.5, 0
    hobj.axon[0].connect(hobj.soma[0], 1.0, 0)
    hobj.axon[1].connect(hobj.axon[0], 1, 0)

    h.define_shape()
