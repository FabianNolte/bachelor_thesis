#include <iostream>
#include <string>
#include <vector>  
#include <algorithm>
#include "../../Header_Files/Data/Setting.h"
using namespace std;


//
//      Setting
//

Setting::Setting(double p_E, vector<double>& p_param, double p_evolution_stepSize){
        E = p_E;
        param = &p_param;
        evolution_stepSize = p_evolution_stepSize;
}

void Setting::printSetting(){
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

double& Setting::get_E(void){
        return E;
}

vector<double>* Setting::get_param(void){
        return param;
}

double& Setting::get_evolution_stepSize(void){
        return evolution_stepSize;
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