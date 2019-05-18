#pragma once
#include <vector>
#include "../Header_Files/Data/Memory.h"
#include "../Header_Files/Data/Setting.h"
#include "../Header_Files/StartFunction.h"
using namespace std;

class Analyser{
    protected:
        Memory* memory;
        Setting* setting;
        StartFunction* startFunction;

        double* tau;
        double* value;
        double* std_value;
        int dataNum;

        virtual void calc_value(void);
        // calc_value - calculates the value of the integral at different tau

    public:
        Analyser(Memory& p_memory, Setting& p_setting, StartFunction& p_startFunction);
        // Analyser - constructor
        // @param Memory& p_memory - memory of the evolution performed
        // @param Setting& p_setting - setting data
        // @param StartFunction& p_startFunction - start function
};

class PrimAnalyser : pulbic Analyser{
    private:
        void calc_value(void) override;
        // calc_value - calculates the value of the integral at different tau
    public:
        PrimAnalyser(Memory& p_memory, Setting& p_setting, StartFunction& p_startFunction);
        // PrimAnalyser - constructor
        // @param Memory& p_memory - memory of the evolution performed
        // @param Setting& p_setting - setting data
        // @param StartFunction& p_startFunction - start function
};