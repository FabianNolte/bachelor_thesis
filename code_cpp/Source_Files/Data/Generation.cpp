#include "../../Header_Files/Data/Generation.h"
#include <iostream>
using namespace std;

Generation::Generation(){}

Generation::Generation(stack<double>* p_x_n, int p_generationNum, double p_totalControlFactor){
    length_x_n = (*p_x_n).size();
    // cout << "Generation constr" << endl;
    // cout << &length_x_n << endl;
    // cout << *&length_x_n << endl;
    x_n = new double[length_x_n];
    for(int i = 0; i < length_x_n; ++i){
        x_n[i] = (*p_x_n).top();
        (*p_x_n).pop();
    }
    generationNum = p_generationNum;
    totalControlFactor = p_totalControlFactor;    
}

Generation::~Generation(){
    delete[] x_n;
}

double& Generation::operator[](int p_i){
    return x_n[p_i];
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

int Generation::get_totalControlFactor(void){
    return totalControlFactor;
}
