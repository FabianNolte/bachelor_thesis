#pragma once
#include <string>
#include <random>
#include <stack>
#include "../Header_Files/EvolutionSetting.h"
#include "../Header_Files/Generation.h"
using namespace std;



class GuidedByHO0_W{
    private:
        double E;
        double m;
        double w;
        double b;
        double evolution_stepSize;

        double sourceSinkTerm(double& p_x_n, int& p_n);
        // sourceSinkTerm - calculates the sourc-sink term
        // @param double& p_x_n - point to evaluate at
        // @param int& p_n - generation to evaluate at
        // @return double - value of the sourc-sink term

    public:
        GuidedByHO0_W();
        // GuidedByHO0_W - constructor;

        GuidedByHO0_W(PrimEvolutionSetting& p_guidedEvolutionSetting);
        // GuidedByHO0_W - constructor;

        double operator() (double& p_x_n, int& p_n);
        // operator() - calculates weight of p_x_n
        // @param double& p_x_n - point to calculate weight for
        // @param int& p_n - generation number
        // @param double - calculated weight

        void opt(double& p_portionToAccept, Generation* p_generation);
        // opt - optimizes E to achive a average weight of p_portionToAccept
        // @param double& p_portionToAccept - average weight to achive
        // @param Generation* p_generation - generation to calculate optimize for
};

class GuidedByHO0_P{
    private:
        double sigma;
        std::random_device rd{};
        std::mt19937 gen{ rd() };
        double m;
        double w;
        double evolution_stepSize;

        double driftTerm(double& p_x_n, int& p_n);
        // driftTerm - calculates the drift term
        // @param double& p_x_n - point to evaluate at
        // @param int& p_n - generation to evaluate at
        // @return double - value of the drift term

    public:
        GuidedByHO0_P();
        // GuidedByHO0_P - constructor

        GuidedByHO0_P(PrimEvolutionSetting& p_guidedEvolutionSetting);
        // GuidedByHO0_P - constructor
         

        stack<double>* operator() (double& p_x_n, int& p_n, int& p_toGenerateNum);
        // operator() - calculates gaussian distributed points arround p_x_n+diftTerm with standart derivation sigma
        // @param double& p_x_n - mean value
        // @param int& p_toGenerateNum - amount of numbers to generate
        // @param int& p_n - generation number
        // @return stack<double>* - stack of generated random numbers
};


// Prim_W, Prim_P create_EvolutionFunction(PrimEvolutionSetting& p_primEvolutionSetting);
// // create_EvolutionFunction - creates for the primitive Evolution the weigth function and the forward function
// // @param PrimEvolutionSetting& p_primEvolutionSetting - settings of the evolution
// // @return Prim_W - weight function
// // @return Prim_P - forward function