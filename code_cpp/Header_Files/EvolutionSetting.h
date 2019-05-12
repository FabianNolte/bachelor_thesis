#pragma once
#include <string>
#include <stack>
#include <vector>
using namespace std;


class PrimEvolutionSetting{
    private:
        double E;
        double m;
        double w;
        double b;
        double evolution_stepSize;
    public:
		PrimEvolutionSetting(double p_E, double p_m, double p_w, double p_b, double p_evolution_stepSize);
		// PrimEvolutionSetting - constructor
		// @param double p_E - energieterm for controling
		// @param double p_m - mass
		// @param double p_w - frequency
		// @param double p_b - prefactor for x**4 term
		// @param double p_evolution_stepSize - size of the evolution steps

        // TODO getter func with return by reference ; faster

        void printSetting(void);
        // printSetting - prints all settings 

        double& get_E(void);
        // get_E - getter function for E
        // @return double& - returns E per reference

        double& get_m(void);
        // get_m - getter function for m
        // @return double& - returns m per reference

        double& get_w(void);
        // get_w - getter function for w
        // @return double& - returns w per reference

        double& get_b(void);
        // get_b - getter function for b
        // @return double& - returns b per reference

        double& get_evolution_stepSize(void);
        // get_evolution_stepSize - getter function for evolution_stepSize
        // @return double& - returns evolution_stepSize per reference
};

// class PrimEvolutionSettingWithEOpt : public PrimEvolutionSetting{
//     public:
//         vector<int> generationToOptE;

// 		PrimEvolutionSettingWithEOpt(int p_evolution_stepNum, double p_evolution_stepSize, double p_E, vector<int> p_generationToOptE);
// 		// PrimEvolutionSettingWithEOpt - constructor with E optimization
// 		// @param int p_evolution_stepNum - number of evolution steps to carry out
// 		// @param double p_evolution_stepSize - size of the evolution steps
// 		// @param double p_E - energieterm for controling
//         // @param vector<int> p_generationToSave - generation which are wanted to be saved (orderd from lowest (bot) to highest (top))
//         // @param vector<int> generationToOptE - generation on which E shall be adjusted

//         // TODO getter func with return by reference ; faster

//         void printSetting(void);
//         // printSetting - prints all settings 
// };