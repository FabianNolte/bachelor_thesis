import numpy as np
from praktikum import analyse as ana
import matplotlib.pyplot as plt
from scipy import special
from scipy import odr
import scipy as sp
import matplotlib.figure
import math
import fnolte_praktikum.ChiqFit as ChiqFit
import matplotlib.patches as mpatches
from fnolte_praktikum.ChiqProb import calcChiqProb
from fnolte_praktikum.ChiqProb import calcChiq
from scipy.special import gamma

path = "Messungen/"
dataname_gm_betrsp = "possion.txt"

binnum = 4

norm = 0

def poisson(params, xs):
    if(type(xs) != type(np.array([]))):
        return norm*params[0]**xs/math.factorial(xs)*np.exp(-params[0])
    toreturn = []
    for x in xs:
        toreturn.append(norm*params[0]**x/math.factorial(x)*np.exp(-params[0]))
    return np.array(toreturn)


def getData(path, dataname):
    rawdata = open("{}{}".format(path, dataname),"r")
    counts = []
    for line in rawdata:
        splited_line = line.rstrip().split("\t")
        counts.append(float(splited_line[0]))
    rawdata.close()
    
    
    return np.array(counts)





def justPlot(ys):
    fig = plt.figure(figsize=(6,6))
    ax1 = plt.axes([.12,.25,.85,.75]) 
    ax2 = plt.axes([.12,.10,.85,.15]) 
#        ax2 = plt.axes([.12,.95,.85,.03]) 
    
    
    
#    
#    minx = min(xs)
#    maxx = max(xs)
#    leftbound = minx-0.02*(maxx-minx)
#    rightbound = maxx+0.02*(maxx-minx)

    bins=np.array([0,1,2,3,4,5,6])-0.5
    mbins = bins[:-1] + 0.5
    histdiff = mbins[1]-mbins[0]


    ns, b_bins, patches = ax1.hist(ys, bins=bins, alpha=0.5, label="data")#, range=None, density=None, weights=None, cumulative=False, bottom=None, histtype='bar', align='mid', orientation='vertical', rwidth=None, log=False, color=None, label=None, stacked=False, normed=None, *, data=None, **kwargs)

    global norm 
    norm = sum(ns)*histdiff
    
    #emp
    mean = sum(ns*mbins)/sum(ns)
    var_emp = sum(ns*(mbins-mean)**2)/(sum(ns)-1)
    er_mean = var_emp/sum(ns)
    er_var_emp = var_emp*(1-2/(sum(ns)-1)*(gamma(sum(ns)/2)/gamma((sum(ns)-1)/2))**2)
    
    print("-emp params:")
    print("--mean =       ", mean)
    print("--er_mean =	  ", er_mean)
    print("--var =        ", var_emp* (sum(ns)-1)/sum(ns))
    print("--er_var =     ", er_var_emp* (sum(ns)-1)/sum(ns))
    
    ax1.errorbar(mbins, poisson([mean], mbins), xerr=[histdiff/2]*len(mbins), ls="none", color="C3", linewidth=3, alpha=0.7)
 

    min_bin = min(bins)
    max_bin = max(bins)
    leftbound = min_bin-0.02*(max_bin-min_bin)
    rightbound = max_bin+0.02*(max_bin-min_bin)
    


    miny = min(ns)
    maxy = max(ns)
    botbound = miny-0.2*(maxy-miny)
    topbound = maxy+0.3*(maxy-miny)

    print(len(ns))
    print(len(b_bins[:-1]))

    print(ns)
    print(b_bins)
    
#    fit_bins = np.array(bins[:5])
#    fit_mbins = np.array(mbins[:5])
#    fit_ns = np.array(ns[:5])
    
    fit_bins = []
    fit_mbins =  []
    fit_ns = []
    
    nofit_bins = []
    nofit_mbins =  []
    nofit_ns = []
    
    for bin_i, mbin_i, n_i in zip(bins, mbins, ns):
        if(n_i >= 4):
            fit_bins.append(bin_i)
            fit_mbins.append(mbin_i)
            fit_ns.append(n_i)
        else:
            nofit_bins.append(bin_i)
            nofit_mbins.append(mbin_i)
            nofit_ns.append(n_i)
            
    fit_bins = np.array(fit_bins)
    fit_mbins = np.array(fit_mbins)
    fit_ns = np.array(fit_ns)  
    nofit_bins = np.array(nofit_bins)
    nofit_mbins = np.array(nofit_mbins)
    nofit_ns = np.array(nofit_ns)    
            
    
    model = ChiqFit.Model(poisson)
    data = ChiqFit.RealData(fit_mbins, fit_ns, sy=np.sqrt(fit_ns))
    myChiqFit = ChiqFit.ChiqFit(data, model, beta0=[2.5], imprBeta=False)
    fited_paramCont = myChiqFit.run()
    
    
    #print ChiqFit
    fited_paramCont.pprint()

    #print EmpFit
    chiq_emp = calcChiq(fit_mbins, fit_ns, poisson, [mean], sy=np.sqrt(fit_ns))
    calcChiqProb(len(mbins)-len(fited_paramCont.beta), chiq=chiq_emp, pprint=True)


    for fit_bin, fit_mbin, fit_n in zip(fit_bins, fit_mbins, fit_ns):
        fited_n = poisson(fited_paramCont.beta, fit_mbin)
        ax1.axvspan(fit_bin+0.02, fit_bin+1-0.02, ymin=(0-botbound)/(topbound-botbound), ymax=(fited_n-botbound)/(topbound-botbound), facecolor ="C1", alpha=0.5, label="fit (used bins)")

    for nofit_bin, nofit_mbin, nofit_n in zip(nofit_bins, nofit_mbins, nofit_ns):
        nofited_n = poisson(fited_paramCont.beta, nofit_mbin)
        ax1.axvspan(nofit_bin+0.02, nofit_bin+1-0.02, ymin=(0-botbound)/(topbound-botbound), ymax=(nofited_n-botbound)/(topbound-botbound), facecolor ="gray", alpha=0.7, label="fit (not used bin)")
        
    ax1.errorbar(bins[:-1]+0.5, ns, xerr=[0.5]*len(ns), yerr=np.sqrt(ns), ls="none", color="C0", alpha=0.7)
    blue_patch = mpatches.Patch(color='C0', alpha=0.5, label='data')
    orange_patch = mpatches.Patch(color='C1', alpha=0.5, label='$\\chi^2$-fit (used bins)')
    gray_patch = mpatches.Patch(color='gray', alpha=0.7, label='$\\chi^2$-fit (not used bins)')
    gree_patch = mpatches.Patch(color="C3", alpha=0.7, label="emp-fit")
    ax1.legend(handles=[blue_patch, orange_patch, gray_patch, gree_patch])

#    ax2.scatter(res_mbins, res_ns)
#    ax2.errorbar(res_mbins, res_ns, yerr=res_er_ns, ls="none")
#    ax2.plot([min(res_mbins), max(res_mbins)], [0,0])
    

    res_bins = fit_bins
    res_mbins = fit_mbins
    res_ns = fit_ns - poisson(fited_paramCont.beta, fit_mbins)
    res_er_ns = np.sqrt(fit_ns)
    
    res_mbins_emp = mbins
    res_ns_emp = ns - poisson([mean], mbins)
    res_er_ns_emp = np.sqrt(ns)    
    
    res_botbound = -7
    res_topbound = 10
    
    
    for res_mbin, res_n in zip(res_mbins, res_ns):
        if(res_n >= 0):
            ax2.axvspan(res_mbin-histdiff/2, res_mbin+histdiff/2, ymin=(0-res_botbound)/(res_topbound-res_botbound), ymax=(res_n-res_botbound)/(res_topbound-res_botbound), facecolor ="C1", alpha=0.4)
        else:
            ax2.axvspan(res_mbin-histdiff/2, res_mbin+histdiff/2, ymin=(res_n-res_botbound)/(res_topbound-res_botbound), ymax=(0-res_botbound)/(res_topbound-res_botbound), facecolor ="C1", alpha=0.4)
    ax2.errorbar(res_mbins, res_ns, xerr=[histdiff/2]*len(res_ns), yerr=res_er_ns, ls="none", color="C1", alpha=0.5)
    
    ax2.errorbar(res_mbins_emp, res_ns_emp, xerr=[histdiff/2]*len(res_ns_emp), ls="none", color="C3", alpha=0.7, linewidth=2)


    red_patch = mpatches.Patch(color='C1', alpha=0.7, label="n - n$_{{\\chi^2-fit}}$")
    green_patch = mpatches.Patch(color='C3', alpha=0.7, label="n - n$_{{emp-fit}}$")
    ax2.legend(handles=[red_patch, green_patch], loc="upper right")
    



#    ax1.legend()
    
#    ax2_yticks = ax2.get_yticks()
    new_ax2_yticks = [-5, 0, 5, 10]
    new_ax2_yticklabels = [-5, 0, 5, 10]
    ax2.set_yticks(new_ax2_yticks)
    ax2.set_yticklabels(new_ax2_yticklabels)
    
  
    ax1.set_xlim(leftbound, rightbound)
    ax1.set_ylim(botbound, topbound)
    ax2.set_xlim(leftbound, rightbound)

    ax2.set_xlabel("count k")
    ax1.set_ylabel("frequency n")
    ax2.set_ylabel("residue")
    




counts = getData(path, dataname_gm_betrsp)

justPlot(counts)
#plt.scatter(voltages, counts)






