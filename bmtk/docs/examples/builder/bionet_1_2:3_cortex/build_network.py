import os
import sys
from optparse import OptionParser
import numpy as np
import pandas as pd
import h5py

from bmtk.builder.networks import NetworkBuilder


def build_l4():
    net = NetworkBuilder("V1/L4")
    net.add_nodes(N=1, pop_name='DG_GC', node_type_id=478230220,
                  positions=[(28.753, -364.868, -161.705)],
                  #tuning_angle=[0.0, 25.0],
                  rotation_angle_yaxis=[3.55501],
                  #location='VisL4',
                  ei='e',
                  level_of_detail='biophysical',
                  params_file='478230220.json',
                  morphology_file='478230220.swc',
                  rotation_angle_zaxis=-3.646878266,
                  set_params_function='Biophys1')

    net.build()
    net.save_nodes(nodes_file_name='output/v1_nodes.h5', node_types_file_name='output/v1_node_types.csv')
  #  net.save_edges(edges_file_name='output/v1_v1_edges.h5', edge_types_file_name='output/v1_v1_edge_types.csv')

    return net

def build_lgn():
    def generate_positions(N, x0=0.0, x1=300.0, y0=0.0, y1=100.0):
        X = np.random.uniform(x0, x1, N)
        Y = np.random.uniform(y0, y1, N)
        return np.column_stack((X, Y))

    def select_source_cells(src_cell, trg_cell, n_syns_exc, n_syns_inh):
        #if trg_cell['tuning_angle'] is not None:
        #    synapses = [n_syns if src['pop_name'] == 'tON' or src['pop_name'] == 'tOFF' else 0 for src in src_cells]
        #else:
        #    synapses = [n_syns if src['pop_name'] == 'tONOFF' else 0 for src in src_cells]

        # will always give synapse number depending on type
        if n_syns_exc > 0:
            n_synapses = n_syns_exc
        if n_syns_inh > 0:
            n_synapses = n_syns_inh

        return n_synapses

        # varible number of synapses
        #return np.random.randint(n_syns_min, n_syns_max)
        #return synapses

    if not os.path.exists('output'):
        os.makedirs('output')

    LGN = NetworkBuilder("LGN")
    LGN.add_nodes(N=1000,
                  positions=generate_positions(1000),
                  location='LGN',
                  level_of_detail='filter',
                  pop_name='ExcIN',
                  ei='e')

    LGN.add_nodes(N=1,
                  positions=generate_positions(1),
                  location='LGN',
                  level_of_detail='filter',
                  pop_name='InhIN',
                  ei='i')
  


    VL4 = NetworkBuilder('V1/L4')
    VL4.import_nodes(nodes_file_name='output/v1_nodes.h5', node_types_file_name='output/v1_node_types.csv')
    cm = VL4.add_edges(source=LGN.nodes(ei='e'), #target={'pop_name': 'DG_GC'},
                  connection_rule=select_source_cells,
                  connection_params={'n_syns_exc': 1, 'n_syns_inh': 0},
                  weight_max=10e-03,
                  weight_function='wmax',
                  distance_range=[1, 1e+20],
                  target_sections=['apical'],
                  delay=2.0,
                  params_file='AMPA_ExcToExc.json',
                  set_params_function='exp2syn')



    VL4.build()
    LGN.save_nodes(nodes_file_name='output/lgn_nodes.h5', node_types_file_name='output/lgn_node_types.csv')
    VL4.save_edges(edges_file_name='output/lgn_v1_edges.h5', edge_types_file_name='output/lgn_v1_edge_types.csv')



if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option("--force-overwrite", dest="force_overwrite", action="store_true", default=False)
    parser.add_option("--out-dir", dest="out_dir", default='./output/')
    parser.add_option("--percentage", dest="percentage", type="float", default=1.0)
    parser.add_option("--with-stats", dest="with_stats", action="store_true", default=False)
    (options, args) = parser.parse_args()

    if not os.path.exists('output'):
        os.makedirs('output')

    l4_network = build_l4()
    build_lgn()
    #build_tw()

