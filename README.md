# The Brain Modeling Toolkit

A software development package for building, simulating and analyzing large-scale networks of different levels of resolution. This particular code has been used for simulating the biophysically detailed neuron model from this manuscript: https://www.sciencedirect.com/science/article/pii/S0896627318309000

## Level of Support
We are releasing this code to the public as a tool we expect others to use. Questions concerning bugs and related issues are welcomed. We expect to address them promptly, pull requests will vetted by our staff before inclusion.


## Quickstart
bmtk requires Python 2.7 plus [additional python dependicies](https://alleninstitute.github.io/bmtk/index.html#base-installation). To install with
base requirements from a command-line:

```bash
 $ git clone https://github.com/AllenInstitute/bmtk.git
 $ cd bmtk
 $ python setup.py develop
```

There are examples of building models and running simulations located in docs/examples/. Some of the simulation engines may require additonal requirements to run.

## Running simulations

Before running the simulations it is necessary to compile the mod files. Go to the folder docs/examples/simulator/bionet/components/mechanisms and compile the mechanisms in Neuron.
```bash
 nrnivmodl ./modfiles
```
To run simualtions go to the folder /docs/examples/simulator/bionet/MODEL. In the corresponding MODEL folder set up the parameters in the config.json (defaul simulation time is 10 ms) and run using python
```bash
 python run_bionet.py
```

The results of the simulation will be saved in the output folder. The folder cellvars will contain the file 0.h5, which will contain the somatic and dendritic voltage changes of the simulated neuron. To change the cell biophysics, for example choose a different Ih distribution go to the folder /docs/examples/simulator/bionet/components/biophysical/electrophysioogy and copy the content of the parameter json file to 478230220.json. Only 478230220.json will be used in the simulation together with 478230220.swc file in the morphology fodler.

In order to change the network properties, go to /docs/examples/builder/bionet_1_2/3_cortex Then run the script to create the network
```bash
 python build_network.py

```

## Changing inputs

In order to change the input to the simulated neuron go to the folder docs/examples/simulator/NWB_files Then run the 
```bash
 python record_spikes_nwb_poisson.py

```
To generate the periodic input choose another file to run: record_spikes_nwb_periodic.py


## Visualisng the results

To visualise the resulting somatic voltage. Copy the voltage_plot.py from /docs/examples/simulator/bionet/MODEL directory to /docs/examples/simulator/bionet/MODEL/output/cellvars. Then run 
```bash
 python voltage_plot.py

```
It will generate the voltage plot as well as save the results into csv format for ruther analysis. The current analysis script assumes that simulations were done with 0.1 ms current step. If you plan to change it, chage the dt parameter as well.

To visualise the input raster to the neuron go to the model folder /docs/examples/simulator/bionet/MODEL directory and run
```bash
 python plot_rasters.py

```
This will generate the input raster plot to the simulated neuron and will compute the average firing rate.s


## Documentation

[User Guide](https://alleninstitute.github.io/bmtk/) 
* [Building network models](https://alleninstitute.github.io/bmtk/builder.html)
* [Running biophysical simulations](https://alleninstitute.github.io/bmtk/bionet.html)
* [Running point-neuron simulations](https://alleninstitute.github.io/bmtk/pointnet.html)
* [Running population-level simulations](https://alleninstitute.github.io/bmtk/popnet.html)
   


Copyright 2018 Allen Institute
