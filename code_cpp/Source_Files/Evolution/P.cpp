//#include <math>
#include <iostream>
#include <stack>
#include <random>
#include "../../Header_Files/Evolution/P.h"
using namespace std;

//
// P
//

P::P(){}

P::P(Setting& p_setting){ evolution_stepSize = p_setting.get_evolution_stepSize(); }

double P::stDeviation(double& p_x_n, int& p_n){ return 1;}

double P::meanShift(double& p_x_n, int& p_n) {return 0;}

stack<double>* P::operator() (double& p_x_n, int& p_n, int& p_toGenerateNum){
	stack<double>* x_nPlus1 = new stack<double>;
	std::normal_distribution<double> gen_x_nPlus1{ p_x_n + meanShift(p_x_n, p_n) ,stDeviation(p_x_n, p_n) };
	for(int i = 0; i < p_toGenerateNum; ++i){
		(*x_nPlus1).push(gen_x_nPlus1(gen));
	}
	return x_nPlus1;
}

//
// Prim_P
//

Prim_P::Prim_P(){}

Prim_P::Prim_P(Setting& p_setting) : P(p_setting){
    stDeviationValue = pow(p_setting.get_evolution_stepSize()/(*(p_setting.get_param()))[0], 0.5);
}

double Prim_P::stDeviation(double& p_x_n, int& p_n){
    return stDeviationValue;
}

double Prim_P::meanShift(double& p_x_n, int& p_n){ return 0; }


//
// GuidedByHO0_P
//

GuidedByHO0_P::GuidedByHO0_P() {}

GuidedByHO0_P::GuidedByHO0_P(Setting& p_setting) : P(p_setting){
    meanShiftFactor = - p_setting.get_evolution_stepSize() * (*(p_setting.get_param()))[1];
    stDeviationValue = p_setting.get_evolution_stepSize() * (1 - p_setting.get_evolution_stepSize() * (*(p_setting.get_param()))[1]);
}


double GuidedByHO0_P::stDeviation(double& p_x_n, int& p_n){
    return stDeviationValue;
}

double GuidedByHO0_P::meanShift(double& p_x_n, int& p_n){
    return meanShiftFactor * p_x_n;
}
