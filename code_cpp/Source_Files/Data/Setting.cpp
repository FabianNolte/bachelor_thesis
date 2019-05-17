#include <iostream>
#include <string>
#include <vector>  
#include <algorithm>
#include "../../Header_Files/Data/Setting.h"
using namespace std;


//
//      Setting
//

Setting::Setting(double p_E, double p_m, double p_w, double p_b, double p_evolution_stepSize){
        E = p_E;
        m = p_m;
        w = p_w;
        b = p_b;
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

double& Setting::get_m(void){
        return m;
}

double& Setting::get_w(void){
        return w;
}

double& Setting::get_b(void){
        return b;
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