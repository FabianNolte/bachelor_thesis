from scipy.stats import chi2
import warnings

warnings.simplefilter('error', UserWarning)



def calcChiqProb(ndf, chiq=None, chiqPndf=None, pprint=None):
    prob = 0
    if(chiq == None):
        chiq = chiqPndf*ndf
    
    prob = 1-chi2.cdf(chiq, ndf)
    if(pprint):
        print("prob(chiq > {:.2f}, ndf={:.0f}) = {}".format(chiq, ndf, prob))
    return prob


def calcChiq(xs, ys, fnc, fnc_params, sx=None, sy=None, diff_fnc=None):
        if(type(sx) == type(None) and type(sy) == type(None)):
            warnings.warn("please insert errors")
            return
        
        if(type(sx) == type(None) and type(diff_fnc) == type(None)):
            return sum((ys-fnc(fnc_params, xs))**2/sy**2)
        elif(type(sx) != type(None) and type(diff_fnc) == type(None)):
            warnings.warn("please insert diff_fnc")
            return
        elif(type(sy) == type(None)):
            return sum((ys-fnc(fnc_params, xs))**2/(diff_fnc(fnc_params, xs) * sx)**2)
        else:
            return sum((ys-fnc(fnc_params, xs))**2/(sy**2 + (diff_fnc(fnc_params, xs) * sx)**2))




