#pragma once
#include <string>
#include <stack>
#include <vector>
using namespace std;


class Setting{
    private:
        double E;
        double m;
        double* pot_param;
        double evolution_stepSize;
        int num_of_memories;
    public:
		Setting(double p_E, double p_m, double* p_pot_param, double p_evolution_stepSize, int p_num_of_memories);
		// Setting - constructor
		// @param double p_E - energieterm for controling
        // @param double p_m - mass
        // @param double* p_pot_param - parameter of the potential
        // @param vector<doulbe>& p_param - params of the weight function
		// @param double p_evolution_stepSize - size of the evolution steps
        // @param int p_num_of_memories - amount of memories to generate

        // TODO getter func with return by reference ; faster

        void printSetting(void);
        // printSetting - prints all settings 

        double& get_E(void);
        // get_E - getter function for E
        // @return double& - returns E per reference

        double& get_m(void);
        // get_m - getter function for m
        // @return double& - returns m per reference

        double* get_pot_param(void);
        // get_pot_param - getter function for pot_param
        // @return double* - returns pot_param

        double& get_evolution_stepSize(void);
        // get_evolution_stepSize - getter function for evolution_stepSize
        // @return double& - returns evolution_stepSize per reference

        int get_num_of_memories(void);
        // get_num_of_memories - getter function for num_of_memories
};

// class SettingWithEOpt : public Setting{
//     public:
//         vector<int> generationToOptE;

// 		SettingWithEOpt(int p_evolution_stepNum, double p_evolution_stepSize, double p_E, vector<int> p_generationToOptE);
// 		// SettingWithEOpt - constructor with E optimization
// 		// @param int p_evolution_stepNum - number of evolution steps to carry out
// 		// @param double p_evolution_stepSize - size of the evolution steps
// 		// @param double p_E - energieterm for controling
//         // @param vector<int> p_generationToSave - generation which are wanted to be saved (orderd from lowest (bot) to highest (top))
//         // @param vector<int> generationToOptE - generation on which E shall be adjusted

//         // TODO getter func with return by reference ; faster

//         void printSetting(void);
//         // printSetting - prints all settings 
// };