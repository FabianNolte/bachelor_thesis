#pragma once
#include <string>
#include <random>
#include <stack>
#include <PathIntegral/Data/Setting.h>
#include <PathIntegral/Data/Generation.h>
using namespace std;


class W{
    protected:
        double E;
        double evolution_stepSize;

        virtual double weight(double& p_x, int& p_n);
        // weight - weight to be aplicated
        // @param double& p_x - point to evaluate the weight at
        // @param int& p_n - generation to evaluate the weight at
        // @return double - value of weight at p_x 

    public:
        W();
        // W - constructor

        W(Setting& p_setting);
        // W - constructor
        // @param p_setting - setting data

        double operator() (double& p_x_n, int& p_n);
        // operator() - calculates weight of p_x_n
        // @param double& p_x_n - point to calculate weight for
        // @param int& p_n - generation number
        // @param double - calculated weight

        void opt(double& p_portionToAccept, Generation* p_generation);
        // opt - optimizes E to achive a average weight of p_portionToAccept
        // @param double& p_portionToAccept - average weight to achive
        // @param Generation* p_generation - generation to calculate optimize for

        double& get_E();
        // get_E - getter function for evolution_stepSize
        // @return double& - E

        double& get_evolution_stepSize(void);
        // get_evolution_stepSize - getter function for evolution_stepSize
        // @return double& - evolution_stepSize
};


class Prim_W : public W{
    private:
        double* pot_param;

        double (*potential)(double p_x, double* p_pot_param);

        double weight(double& p_x, int& p_n) override;
        // weight - pyhsical potential to analyse
        // @param double& p_x - point to evaluate the potential at
        // @param int& p_n - generation to evaluate the weight at
        // @return double - value of potential at p_x 

    public:
        Prim_W();
        // Prim_W - constructor;

        Prim_W(Setting& p_setting, double (*p_potential)(double p_x, double* p_pot_param));
        // Prim_W - constructor;
        // @param p_setting - setting data
        // @param double (*p_potential)(double p_x, double* p_pot_param) - physical potential
};


// class GuidedByHO0_W : public W{
//     private:
//         double b;

//         double weight(double& p_x_n, int& p_n) override;
//         // weight - calculates the sourc-sink term
//         // @param double& p_x_n - point to evaluate at
//         // @param int& p_n - generation to evaluate at
//         // @return double - value of the sourc-sink term

//     public:
//         GuidedByHO0_W();
//         // GuidedByHO0_W - constructor;

//         GuidedByHO0_W(Setting& p_guidedSetting);
//         // GuidedByHO0_W - constructor;
//         // @param p_setting - setting data   
// };