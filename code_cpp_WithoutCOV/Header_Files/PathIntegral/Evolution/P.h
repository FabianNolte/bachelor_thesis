#pragma once
#include <string>
#include <random>
#include <stack>
#include <PathIntegral/Data/Setting.h>
#include <PathIntegral/Data/Generation.h>
using namespace std;

class P{
    protected:
        std::random_device rd{};
        std::mt19937 gen{ rd() };
        double evolution_stepSize;
    
        virtual double stDeviation(double& p_x_n, int& p_n);
        // stDeviation - calculates the standart deviation 
        // @param double& p_x_n - point to calculate for
        // @param int& p_n - generation to evaluate at
        // @return double - value of the standart deviation

        virtual double meanShift(double& p_x_n, int& p_n);
        // meanShift - calculates the shift of the mean value
        // @param double& p_x_n - point to calculate for
        // @param int& p_n - generation to evaluate at
        // @return double - value of the mean shift

    public:
        P();
        // P - constructor

        P(Setting& p_setting);
        // P - constructor
        // @param p_setting - setting data

        stack<double>* operator() (double& p_x_n, int& p_n, int& p_toGenerateNum);
        // operator() - calculates gaussian distributed points arround p_x_n with standart derivation sigma
        // @param double& p_x_n - mean value
        // @param int& p_toGenerateNum - amount of numbers to generate
        // @param int& p_n - generation number
        // @return stack<double>* - stack of generated random numbers
};

class Prim_P : public P{
    private:
        double stDeviationValue;

        double stDeviation(double& p_x_n, int& p_n) override;
        // stDeviation - calculates the standart deviation 
        // @param double& p_x_n - point to calculate for
        // @param int& p_n - generation to evaluate at
        // @return double - value of the standart deviation

        double meanShift(double& p_x_n, int& p_n) override;
        // meanShift - calculates the shift of the mean value
        // @param double& p_x_n - point to calculate for
        // @param int& p_n - generation to evaluate at
        // @return double - value of the mean shift

    public:
        Prim_P();
        // Prim_P - constructor

        Prim_P(Setting& p_setting);
        // Prim_P - constructor
        // @param p_setting - setting data     
};

// class GuidedByHO0_P : public P{
//     private:
//         double stDeviationValue;
//         double meanShiftFactor;

//         double stDeviation(double& p_x_n, int& p_n) override;
//         // stDeviation - calculates the standart deviation 
//         // @param double& p_x_n - point to calculate for
//         // @param int& p_n - generation to evaluate at
//         // @return double - value of the standart deviation

//         double meanShift(double& p_x_n, int& p_n) override;
//         // meanShift - calculates the drift term
//         // @param double& p_x_n - point to calculate for
//         // @param int& p_n - generation to evaluate at
//         // @return double - value of the drift term

//     public:
//         GuidedByHO0_P();
//         // GuidedByHO0_P - constructor

//         GuidedByHO0_P(Setting& p_Setting);
//         // GuidedByHO0_P - constructor
//         // @param p_setting - setting data   
// };