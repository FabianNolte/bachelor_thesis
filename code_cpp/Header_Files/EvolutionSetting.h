#pragma once
#include <string>
#include <stack>
using namespace std;


class EvolutionSetting{
    public:
        int evolution_stepNum;
        double evolution_stepSize;
        double E;
        double (*W_x_n)(double, double, double); 
        stack<double>* (*P_x_n_to_x_nPlus1)(double, double, int);
        stack<int>* generationToSave;

        EvolutionSetting();
        // EvolutionSetting - constructor

		EvolutionSetting(int p_evolution_stepNum, double p_evolution_stepSize, double p_E, double (*p_W_x_n)(double, double, double), stack<double>* (*p_P_x_n_to_x_nPlus1)(double, double, int), stack<int>* p_generationToSave);
		// EvolutionSetting - constructor
		// @param int p_evolution_stepNum - number of evolution steps to carry out
		// @param double p_evolution_stepSize - size of the evolution steps
		// @param double p_E - energieterm for controling
		// @param double (*p_W_x_n)(double, double, double) - weight function
		// @param stack<double>* (*p_P_x_n_to_x_nPlus1)(double, double, int) - function for generating the next evolution step
        // @param stack<int>* p_generationToSave - generation which are wanted to be saved (orderd from lowest (bot) to highest (top))

        void printSetting(void);
        // printSetting - prints all settings 
};