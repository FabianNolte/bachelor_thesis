#include "../Header_Files/Generation.h"
#include <iostream>
using namespace std;

Generation::Generation(){}

Generation::Generation(stack<double>* p_x_n, int p_generationNum){
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
}

Generation::~Generation(){
    delete[] x_n;
}
        
void Generation::set_savePosition(string p_savePosition){
    savePosition = p_savePosition;
}

void Generation::set_plotPosition(string p_plotPosition){
    plotPosition = p_plotPosition;
}

double* Generation::get_x_n(void){
    return x_n;
}


int Generation::get_length_x_n(void){
    return length_x_n;
}


string Generation::get_savePosition(void){
    return savePosition;
}

string Generation::get_plotPosition(void){
    return plotPosition;
}