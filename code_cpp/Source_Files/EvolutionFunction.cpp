//#include <math>
#include <stack>
#include <random>
#include "../Header_Files/EvolutionFunction.h"
using namespace std;

// Prim_W, Prim_P create_EvolutionFunction(PrimEvolutionSetting& p_primEvolutionSetting){
//     return Prim_W(p_primEvolutionSetting), Prim_P(p_primEvolutionSetting);
// }

Prim_W::Prim_W(){}

Prim_W::Prim_W(PrimEvolutionSetting& p_primEvolutionSetting){
    E = p_primEvolutionSetting.get_E();
    m = p_primEvolutionSetting.get_m();
    w = p_primEvolutionSetting.get_w();
    b = p_primEvolutionSetting.get_b();
    evolution_stepSize = p_primEvolutionSetting.get_evolution_stepSize();
}

double Prim_W::potential(double& p_x){
    return 0.5* m* pow(w, 2)* pow(p_x-5, 2) + b * pow(p_x, 4);
}

double Prim_W::operator() (double& p_x_n){
    return exp(-evolution_stepSize * (potential(p_x_n) - E));
}

Prim_P::Prim_P(){}

Prim_P::Prim_P(PrimEvolutionSetting& p_primEvolutionSetting){
    sigma = pow(p_primEvolutionSetting.get_evolution_stepSize()/p_primEvolutionSetting.get_m(), 0.5);
}

stack<double>* Prim_P::operator() (double& p_x_n, int& p_toGenerateNum){
	stack<double>* x_nPlus1 = new stack<double>;
	std::normal_distribution<double> gen_x_nPlus1{ p_x_n,sigma };
	for(int i = 0; i < p_toGenerateNum; ++i){
		(*x_nPlus1).push(gen_x_nPlus1(gen));
	}
	return x_nPlus1;
}

