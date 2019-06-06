#include <PathIntegral/Data/Generation.h>
#include <iostream>
using namespace std;

Generation::Generation(){}

Generation::Generation(double* p_x_n, int p_length_x_n, double& p_normFactor_n, double& p_std_normFactor_n, int p_generationNum, double p_totalControlFactor){
    x_n = p_x_n;
    length_x_n = p_length_x_n;
    normFactor_n = p_normFactor_n;
    std_normFactor_n = p_std_normFactor_n;
    // cout << "Generation constr" << endl;
    // cout << &length_x_n << endl;
    // cout << *&length_x_n << endl;
    generationNum = p_generationNum;
    //cout << p_totalControlFactor << endl;
    totalControlFactor = p_totalControlFactor;    
}

Generation::~Generation(){
    delete[] x_n;
}

double& Generation::operator[](int p_i){
    return x_n[p_i];
}

double* Generation::get_x_n(void){
    return x_n;
}
        
void Generation::set_savePosition(string p_savePosition){
    savePosition = p_savePosition;
}

void Generation::set_plotPosition(string p_plotPosition){
    plotPosition = p_plotPosition;
}

int Generation::get_length_x_n(void){
    return length_x_n;
}

double& Generation::get_normFactor_n(void){
    return normFactor_n;
}

double& Generation::get_std_normFactor_n(void){
    return std_normFactor_n;
}

double& Generation::get_totalControlFactor(void){
    return totalControlFactor;
}
