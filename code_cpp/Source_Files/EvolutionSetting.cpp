#include <iostream>
#include <string>
#include "../Header_Files/EvolutionSetting.h"
using namespace std;

EvolutionSetting::EvolutionSetting(int p_evolution_stepNum, double p_evolution_stepSize, double p_E, double (*p_W_x_n)(double, double, double), stack<double>* (*p_P_x_n_to_x_nPlus1)(double, double, int), stack<int>* p_generationToSave){
        evolution_stepNum = p_evolution_stepNum;
        evolution_stepSize = p_evolution_stepSize;
        E = p_E;
        W_x_n = p_W_x_n; 
        P_x_n_to_x_nPlus1 = p_P_x_n_to_x_nPlus1;
        generationToSave = p_generationToSave;
}

EvolutionSetting::EvolutionSetting(){}

void EvolutionSetting::printSetting(){
        int size = (*generationToSave).size();
        int array_generationToSave[size];
        for(int i = 0; i < size; ++i){
                array_generationToSave[i] = (*generationToSave).top();
                (*generationToSave).pop();
        }
        for(int i = size-1; i >= 0; --i){
                (*generationToSave).push(array_generationToSave[i]);
        }

        cout << endl << endl;
        cout << "-------Setting-------" << endl;
        cout << "evolution_stepNum = " << evolution_stepNum << endl;
        cout << "evolution_stepSize = " << evolution_stepSize << endl;
        cout << "E = " << E << endl;
        cout << "generationToSave: " ;
        for (int i = 0; i < size; ++i){
                cout << array_generationToSave[i] << " , ";
        }
        cout << endl << endl; 

}