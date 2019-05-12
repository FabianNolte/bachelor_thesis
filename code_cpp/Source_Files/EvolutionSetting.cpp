#include <iostream>
#include <string>
#include <vector>  
#include <algorithm>
#include "../Header_Files/EvolutionSetting.h"
using namespace std;


//
//      PrimEvolutionSetting
//

PrimEvolutionSetting::PrimEvolutionSetting(double p_E, double p_m, double p_w, double p_b, double p_evolution_stepSize){
        E = p_E;
        m = p_m;
        w = p_w;
        b = p_b;
        evolution_stepSize = p_evolution_stepSize;
}

void PrimEvolutionSetting::printSetting(){
        cout << endl << endl;
        cout << "-------Setting-------" << endl;
        cout << "evolution_stepSize = " << evolution_stepSize << endl;
        cout << "E = " << E << endl;
        // cout << "generationToCalc: " ;
        // for (int& genNumToCalc : *generationToCalc){
        //         cout << genNumToCalc << " , ";
        // }
        cout << endl << endl; 

}

double& PrimEvolutionSetting::get_E(void){
        return E;
}

double& PrimEvolutionSetting::get_m(void){
        return m;
}

double& PrimEvolutionSetting::get_w(void){
        return w;
}

double& PrimEvolutionSetting::get_b(void){
        return b;
}

double& PrimEvolutionSetting::get_evolution_stepSize(void){
        return evolution_stepSize;
}

// //
// //      PrimEvolutionSettingWithEOpt
// //

// PrimEvolutionSettingWithEOpt::PrimEvolutionSettingWithEOpt(int p_evolution_stepNum, double p_evolution_stepSize, double p_E, vector<int>* p_generationToSave, vector<int>* p_generationToOptE) : PrimEvolutionSetting(p_evolution_stepNum, p_evolution_stepSize, p_E, p_generationToSave){
//         generationToOptE = p_generationToOptE;
// }

// void PrimEvolutionSettingWithEOpt::printSetting(){
//         cout << endl << endl;
//         cout << "-------Setting-------" << endl;
//         cout << "evolution_stepNum = " << evolution_stepNum << endl;
//         cout << "evolution_stepSize = " << evolution_stepSize << endl;
//         cout << "E = " << E << endl;
//         cout << "generationToSave: " ;
//         for (int& genNumToSave : *generationToSave){
//                 cout << genNumToSave << " , ";
//         }
//         cout << endl;
//         cout << "generationToOptE: ";
//         for (int& genNumToOptE : *generationToOptE){
//                 cout << genNumToOptE << " , ";
//         }
//         cout << endl << endl; 
// }