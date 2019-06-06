import numpy as np
from praktikum import analyse as ana
import matplotlib.pyplot as plt
from scipy.optimize import minimize
from scipy import odr
import scipy as sp
import numdifftools
import warnings
#import fnolte_praktikum.ChiqProb as ChiqProb

warnings.simplefilter('error', UserWarning)


class Model:
    def __init__(self, fcn, diff_fcn=None):
        self.fcn = fcn
        self.diff_fcn = diff_fcn
        self.b_sx = True
        if(diff_fcn == None):
            self.xer = False

class RealData:
    def __init__(self, x, y, sx=None, sy=None):
        self.x = x
        self.y = y
        self.sx = sx
        self.sy = sy
        
        self.b_sx = True
        self.b_sy = True
        
        if(type(sx) == type(None)):
            self.b_sx = False
        if(type(sy) == type(None)):
            self.b_sy = False
        
    def pprint(self):
        print()
        print("x: ", self.x)
        print("y: ", self.y)
        print("sx: ", self.sx)
        print("sy: ", self.sy)
        print()

class Output:
    def __init__(self, beta, cov_beta, chiq, chiqPndf, ndf):
        self.beta = beta
        self.cov_beta = cov_beta
        self.chiq = chiq
        self.chiqPndf = chiqPndf
        self.ndf = ndf
        
    def pprint(self):
        print()
        print("Beta: ", self.beta)
        print("Beta Covariance: ", self.cov_beta)
        print("chiq: ", self.chiq)
        print("chiq/ndf: ", self.chiqPndf)
        print("ndf: ", self.ndf)
       # print("prob(chiq > {:.2f}, ndf={}) = {}".format(self.chiq, self.ndf, ChiqProb.calcChiqProb(self.ndf, chiq=self.chiq)))
        print()
        

class ChiqFit:

    def __init__(self, data, model, beta0=None, imprBeta = True, justODR = False):
        self.data = data
        self.model = model
        self.beta0 = beta0
        self.imprBeta = imprBeta
        self.justODR = justODR

        
    def chiq(self, params):
        if(self.data.b_sx == False):
            return sum((self.data.y-self.model.fcn(params, self.data.x))**2/(self.data.sy**2))
        return sum((self.data.y-self.model.fcn(params, self.data.x))**2/(self.data.sy**2+ (self.model.diff_fcn(params, self.data.x) * self.data.sx)**2))


    def odr_fit(self):
        model = odr.Model(self.model.fcn)
        if(self.data.b_sx):
            mydata = odr.RealData(self.data.x, self.data.y, sx=self.data.sx, sy=self.data.sy)
        else:
            mydata = odr.RealData(self.data.x, self.data.y, sy=self.data.sy)
            
        myodr = odr.ODR(mydata, model, beta0=self.beta0)
        myoutput = myodr.run()
        self.data.impr_beta0 = myoutput.beta
        return myoutput
        
    def run(self):
        if(self.justODR):
            odr_output = self.odr_fit() 
            ndf = len(self.data.x)-len(odr_output.beta)
            chiq = self.chiq(odr_output.beta)
            return Output(odr_output.beta, odr_output.cov_beta, chiq, chiq/ndf, ndf)
        
        if(self.model.b_sx == False & self.data.b_sx == True):
            warnings.warn("please insert diff_fnc")
            return
        
        if(self.imprBeta):
            self.odr_fit()            
        else:
            self.data.impr_beta0 = self.beta0
            
        res = minimize(self.chiq, self.data.impr_beta0, method="nelder-mead")
        hessian = np.array(numdifftools.Hessian(self.chiq,step=1.0e-4)(res.x))  
        
        print(hessian)
        
        cov = np.linalg.inv(0.5*hessian)
        ndf = len(self.data.x)-len(res.x)
        chiq = self.chiq(res.x)
        
        return Output(res.x, cov, chiq, chiq/ndf, ndf)











