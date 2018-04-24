import numpy as np
import matplotlib.pylab as plt
Sol=np.genfromtxt('diffusion.txt')
index=Sol[:,0]==0.0150003
index2=Sol[:,0]==0
plt.plot(Sol[index,1],Sol[index,2],color='midnightblue',label='final')
plt.plot(Sol[index2,1],Sol[index2,2],color='mediumseagreen',label='inicial')
plt.legend()
plt.savefig('escalon.png')
