#pragma once
#include <cmath>
#include <string>
#include <TDataType.h>
#include <TMinuit.h>
using namespace std;

void nonMember_chiq(int &npar, double *gin, double &f, double *par, int iflag);


class Model{
    friend class ChiqFit;
    private:
        double (*fnc)(double*, int, double);
       // double (*diff_fnc)(double*, int, double);
    public:
        Model(double (*p_fnc)(double*, int, double));//, 
           // double (*p_diff_fnc)(double*, int, double)=nullptr);
        // Model - constructor
        // @param double (*p_fnc)(double*, int, double) - function to be fitted
        // @param double (*p_diff_fnc)(double*, int, double)=nullptf - differentiated function (only used of fits with y error)
};

class RealData{
    friend class ChiqFit;
    private:
        double* x;
        double* y;
        double* sx;
        double* sy;
        int pointNum;

        bool b_sx;
        bool b_sy;
    public:
        RealData(int p_pointNum, 
                double* p_x, 
                double* p_y, 
               // double* p_sx=nullptr, 
                double* p_sy);
        // RealData - constructor
        // @param int p_pointNum - number of points to be storaged
        // @param double* p_x - x points
        // @param double* p_y - y points
        // @param double* p_sx=nullptf - x errors
        // @param double* p_sy - potential y errors

        void pprint(void);
        // pprint - prints the contained data
};

class Output{
    public:
        double* beta;
        double* sbeta;
        string* beta_label;
        int len_beta;
        double chiq;
        double chiqPndf;
        int ndf;
        double chiqProb;

        Output(double* p_beta, 
            double* p_sbeta,
            string* p_beta_label, 
            int p_len_beta,
            double p_chiq, 
            double p_chiqPndf,
            int p_ndf,
            double p_chiqProb);
        // Output - constructor
        // @param double* p_beta - fitted parameter
        // @param double* p_sbeta - error on fitted parameter
        // @param string* p_beta_label - parameter label
        // @param int p_len_beta - number of fitting parameter
        // @param double p_chiq - chiq corresponding to the fit
        // @param double p_chiqPndf - chi per degree of freedom
        // @param int p_ndf - number of degrees of freedom 
        // @param double p_chiqProf - propability corresponding to the chiq and the ndf

        void pprint(void);
        // pprint - prints fitting results
};

class ChiqFit{
    friend void nonMember_chiq(int&, double*, double&, double*, int);
    private:
        RealData* data;
        Model* model;
        string* paramLabel;
        double* beta0;
        double* sbeta0;
        int len_beta0;

    public:
        TMinuit* minuit;

        ChiqFit(RealData& p_data, 
                Model& p_model,
                string* p_paramLabel,
                double* p_beta0,
                double* p_sbeta0,
                int p_len_beta0);
        // ChiqFit - constructor
        // @param RealData& p_data - data object containing the datapoints
        // @param Model& p_model - model object containing the function to be fitted
        // @param string* p_paramLabel - array with labels of the parameter
        // @param double* p_beta0 - array of intitial parameter
        // @param double* p_sbeta0 - array of errors of the initial parameter
        // @param int p_len_beta0 - number of parameter

        Output run(void);
        // run - executes the fitting 
        // @return Output - returns an output object containing the fitted parameter

        // TODO update doc
        void calc_chiq(int &npar, double *gin, double &f, double *par, int iflag);
        // calc_chiq - calculates chiq for choosen parameter
        // @param Double_t &p_fval - chiq value to be modified
        // @param Double_t *p_param - array with given parameter
};



