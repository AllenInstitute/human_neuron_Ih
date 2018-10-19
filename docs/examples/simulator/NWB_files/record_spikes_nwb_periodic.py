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
time_start=1         # sec
time_end=2           # sec
freq=float(200)        # Hz



for i in range(N):
    path_name='processing/trial_0/spike_train/'+str(i)+'/data'

    # record periodic spike train, everything in ms
    spike_train=np.arange(time_start,time_end,1/freq)*1000

    del f[path_name]
    f.create_dataset(path_name, data=spike_train)

f.close()

print 'Operation is done'