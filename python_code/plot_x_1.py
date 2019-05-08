import sys
import numpy as np
import matplotlib.pyplot as plt

def getData(path, dataname):
    rawdata = open("{}{}.txt".format(path, dataname),"r")
    x_1 = []
    for line in rawdata:
        splited_line = line.rstrip().split("\t")
        x_1.append(float(splited_line[0]))
    rawdata.close()
    
    
    return np.array(x_1)


print('Number of arguments:', len(sys.argv), 'arguments.')
print('Argument List:', str(sys.argv))


path = sys.argv[1]
dataname = sys.argv[2]
left = float(sys.argv[3])
right = float(sys.argv[4])
histnum = int(sys.argv[5])

x_1 = getData(path, dataname)
print(x_1)


fig = plt.figure(figsize=(6,6))
ax1 = plt.axes([.12,.15,.85,.75]) 

bins = np.linspace(left, right, histnum+1)
ns, b_bins, patches = ax1.hist(x_1, bins=bins, alpha=0.5, label="data")

plt.savefig("../images/x_1.pdf", format="pdf")