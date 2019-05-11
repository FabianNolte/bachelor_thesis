import sys
import numpy as np
import matplotlib.pyplot as plt

def getData(path, dataname):
    rawdata = open("{}{}.txt".format(path, dataname),"r")
    x_0 = []
    for line in rawdata:
        splited_line = line.rstrip().split("\t")
        x_0.append(float(splited_line[0]))
    rawdata.close()
    
    
    return np.array(x_0)


print('Number of arguments:', len(sys.argv), 'arguments.')
print('Argument List:', str(sys.argv))


path = sys.argv[1]
dataname = sys.argv[2]
left = float(sys.argv[3])
right = float(sys.argv[4])
histnum = int(sys.argv[5])

x_0 = getData(path, dataname)
print(x_0)


fig = plt.figure(figsize=(6,6))
ax1 = plt.axes([.12,.15,.85,.75]) 

bins = np.linspace(left, right, histnum+1)
ns, b_bins, patches = ax1.hist(x_0, bins=bins, alpha=0.5, label="data")

plt.savefig("../images/{}.pdf".format(dataname), format="pdf")

print(len(x_0))