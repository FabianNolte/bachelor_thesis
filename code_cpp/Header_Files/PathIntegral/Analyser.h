#pragma once
#include <vector>
#include <string>

#include <PathIntegral/StartFunction.h>

#include <PathIntegral/Data/AnalyserData.h>
#include <PathIntegral/Data/MemoryWrapper.h>
#include <PathIntegral/Data/Memory.h>
#include <PathIntegral/Data/Setting.h>
using namespace std;


double fit_fcn(double* pam, int npam, double x);
// fit_fnc - function to be fitted
// @param double* pam - array with parameter
// @param int npam - number of parameter
// @param double x - point to evaluate at
// @return doulbe - value of the function

class Analyser{
    protected:
        MemoryWrapper* memoryWrapper;
        Setting* setting;
        StartFunction* startFunction;

        AnalyserData* analyserData;


        virtual void calc_value(void);
        // calc_value - calculates the value of the integral at different tau

        double calc_moment(Generation* p_generation, int p_order);
        // calc_moment - calculates the p_order moment of the startfunction with a distribution according to p_generation
        // @param Generation* p_generation - distribution to calculate the moment at
        // @param int p_order - order of the moment
        // @return double - value of the moment

    public:
        Analyser(MemoryWrapper& p_memoryWrapper, Setting& p_setting, StartFunction& p_startFunction);
        // Analyser - constructor
        // @param MemoryWrapper& p_memoryWrapper - memorie of the evolution performed
        // @param Setting& p_setting - setting data
        // @param StartFunction& p_startFunction - start function

        ~Analyser(void);
        // ~Analyser - destructor

        void print_data(void);
        // print_data - prints data

        void plot_data(string p_path);
        // plot_data - plots the data
        // @param string p_path - path to save to

        // TODO doc
        void fit_data(int p_NumOfEnergies, double p_minTau);
};

class PrimAnalyser : public Analyser{
    private:
        void calc_value(void) override;
        // calc_value - calculates the value of the integral at different tau
    public:
        PrimAnalyser(MemoryWrapper& p_memoryWrapper, Setting& p_setting, StartFunction& p_startFunction);
        // PrimAnalyser - constructor
        // @param MemoryWrapper& p_memoryWrapper - memories of the evolution performed
        // @param Setting& p_setting - setting data
        // @param StartFunction& p_startFunction - start function
};

