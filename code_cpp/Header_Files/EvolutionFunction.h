#pragma once
#include <string>
#include <random>
#include <stack>
#include "../Header_Files/EvolutionSetting.h"
using namespace std;



class Prim_W{
    private:
        double E;
        double m;
        double w;
        double b;
        double evolution_stepSize;

        double potential(double& p_x);
        // potential - pyhsical potential to analyse
        // @param double& p_x - point to evaluate the potential at
        // @return double - value of potential at p_x 

    public:
        Prim_W();
        // Prim_W - constructor;

        Prim_W(PrimEvolutionSetting& p_primEvolutionSetting);
        // Prim_W - constructor;

        double operator() (double& p_x_n);
        // operator() - calculates weight of p_x_n
        // @param double& p_x_n - point to calculate weight for
        // @param double - calculated weight
};

class Prim_P{
    private:
        double sigma;
        std::random_device rd{};
        std::mt19937 gen{ rd() };
    public:
        Prim_P();
        // Prim_P - constructor

        Prim_P(PrimEvolutionSetting& p_primEvolutionSetting);
        // Prim_P - constructor

         

        stack<double>* operator() (double& p_x_n, int& p_toGenerateNum);
        // operator() - calculates gaussian distributed points arround p_x_n with standart derivation sigma
        // @param double& p_x_n - mean value
        // @param int& p_toGenerateNum - amount of numbers to generate
        // @return stack<double>* - stack of generated random numbers
};


// Prim_W, Prim_P create_EvolutionFunction(PrimEvolutionSetting& p_primEvolutionSetting);
// // create_EvolutionFunction - creates for the primitive Evolution the weigth function and the forward function
// // @param PrimEvolutionSetting& p_primEvolutionSetting - settings of the evolution
// // @return Prim_W - weight function
// // @return Prim_P - forward function