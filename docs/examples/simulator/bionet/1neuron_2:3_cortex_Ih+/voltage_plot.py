import h5py
import matplotlib.pyplot as plt
import numpy as np

#change the figures size
fig_size = plt.rcParams["figure.figsize"]
fig_size[0] = 16
fig_size[1] = 4
plt.rcParams["figure.figsize"] = fig_size    

# take the file
f=h5py.File('0.h5','a')

# record the voltage
voltage=f['v'].value
dt=0.1
time = np.arange(0, len(voltage)) * (1.0 / int(1/dt))

#close the file
f.close()

#plot the voltage
plt.plot(time, voltage)
plt.title('Somatic voltage')
plt.xlabel('Time (ms)')
plt.ylabel('Vs (mV)')
#plt.ylim((-85, -84))
#plt.xlim((3000,5000))

#export the data to csv
a= np.zeros((len(time), 2))
a[:,0]=time
a[:,1]=voltage
np.savetxt('voltage.csv', a, delimiter=",")


#save figure
plt.savefig('Vs.eps', format='eps', dpi=300)

# show it
#plt.show()

