# import the necassary libraries
import h5py
import math
import random
import numpy as np


def nextTime(rateParameter):
    return -math.log(1.0 - random.random()) / rateParameter

# read/update existing nwb file
infile='lgn_spikes.nwb'

# open file for reading
f = h5py.File(infile, "a")

# Operations with the spike train 
cells=f['processing/trial_0/spike_train']
cell=f['processing/trial_0/spike_train/0']

print 'Number of cells'
print len(cells)

N=len(cells)
# total time and time distrete steps
N_spikes=1000
rate=3


for i in range(N):
    path_name='processing/trial_0/spike_train/'+str(i)+'/data'

    # replace all the data with the new spike train

    # CHECK THE DIMENSIONALITY

    # spike train times should be in ms
    spike_train=[random.expovariate(rate) for i in range(N_spikes)]
    # get the value in ms
    spike_train = [i * 1000000 for i in spike_train]
    spike_train=sorted(spike_train)

    del f[path_name]
    f.create_dataset(path_name, data=spike_train)

f.close()

print 'Operation is done'