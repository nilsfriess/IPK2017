import numpy as np
import matplotlib.pyplot as mpl
import sys

points = np.loadtxt(sys.argv[1],skiprows=1)
hull   = np.loadtxt(sys.argv[2],skiprows=1)
hull   = list(hull)
hull.append(hull[0])

mpl.plot(points[:,0], points[:,1], 'o')
mpl.plot(points[hull,0],points[hull,1],'r-')
mpl.plot(points[hull[0],0],points[hull[0],1],'r-')
mpl.savefig("convex-hull.pdf")
