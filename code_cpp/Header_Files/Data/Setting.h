#pragma once
#include <string>
#include <stack>
#include <vector>
using namespace std;


class Setting{
    private:
        double E;
        vector<double>* param;
        double evolution_stepSize;
    public:
		Setting(double p_E, vector<double>& p_param, double p_evolution_stepSize);
		// Setting - constructor
		// @param double p_E - energieterm for controling
        // @param vector<doulbe>& p_param - params of the weight function
		// @param double p_evolution_stepSize - size of the evolution steps

        // TODO getter func with return by reference ; faster

        void printSetting(void);
        // printSetting - prints all settings 

        double& get_E(void);
        // get_E - getter function for E
        // @return double& - returns E per reference

        vector<double>* get_param(void);
        // get_param - getter function for param
        // @return vector<double>* - returns param

        double& get_evolution_stepSize(void);
        // get_evolution_stepSize - getter function for evolution_stepSize
        // @return double& - returns evolution_stepSize per reference
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