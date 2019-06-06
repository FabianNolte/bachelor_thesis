#include <iostream>
#include <string>
#include <vector>  
#include <algorithm>
#include <PathIntegral/Data/Setting.h>
using namespace std;


//
//      Setting
//

Setting::Setting(double p_E, double p_m, double* p_pot_param, double p_evolution_stepSize, int p_num_of_memories){
        E = p_E;
        m = p_m;
        pot_param = p_pot_param;
        evolution_stepSize = p_evolution_stepSize;
        num_of_memories = p_num_of_memories;
}

void Setting::printSetting(){
        cout << endl << endl;
        cout << "-------Setting-------" << endl;
        cout << "evolution_stepSize = " << evolution_stepSize << endl;
        cout << "E = " << E << endl;
        cout << "number of memories = " << num_of_memories << endl;
        // cout << "generationToCalc: " ;
        // for (int& genNumToCalc : *generationToCalc){
        //         cout << genNumToCalc << " , ";
        // }
        cout << endl << endl; 

}

double& Setting::get_E(void){
        return E;
}

double& Setting::get_m(void){
        return m;
}

double* Setting::get_pot_param(void){
        return pot_param;
}

double& Setting::get_evolution_stepSize(void){
        return evolution_stepSize;
}

int Setting::get_num_of_memories(void){
        return num_of_memories;
}

// //
// //      SettingWithEOpt
// //

// SettingWithEOpt::SettingWithEOpt(int p_evolution_stepNum, double p_evolution_stepSize, double p_E, vector<int>* p_generationToSave, vector<int>* p_generationToOptE) : Setting(p_evolution_stepNum, p_evolution_stepSize, p_E, p_generationToSave){
//         generationToOptE = p_generationToOptE;
// }

// void SettingWithEOpt::printSetting(){
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