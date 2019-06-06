#pragma once
#include <PathIntegral/Data/Generation.h>
using namespace std;



class StartFunction{
    protected:
        double max_startFunction;

    public:

        virtual double operator() (double& p_x);
        // operator() - calculates the value of the given start function at p_x
        // @param double& p_x - point to evaluate the start function at
        // @return double - value of the start function

        Generation* calc_startingGeneration(const double* p_sampleArea, const int& p_numberOfPoints);
        // calc_startingGeneration - generates a starting generation according to the start function
        // @param const double* p_sampleArea - array with left and right boundary of the area in which the start function shall be sampled
        // @param const int& p_numberOfPoints - number of points to be generated according to the start function
};

class StartFunctionHO0 : public StartFunction{
    private:
        double m;
        double w;
        const double PI = 3.141592653589793238463;

    public:
        StartFunctionHO0();
        // StartFunctionHO0 - constructor;

        StartFunctionHO0(const double& p_m, const double& p_w);
        // StartFunctionHO0 - constructor;
        // @param const double& p_m - mass of the given pyhsical system
        // @param const double& p_w - frequency of the given quadratic physical system

        double operator() (double& p_x);
        // operator() - calculates the value of the given start function at p_x
        // @param double& p_x - point to evaluate the start function at
        // @return double - value of the start function
};