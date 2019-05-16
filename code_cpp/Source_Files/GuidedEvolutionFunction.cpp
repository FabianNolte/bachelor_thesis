//#include <math>
#include <iostream>
#include <stack>
#include <random>
#include "../Header_Files/GuidedEvolutionFunction.h"
#include "../Header_Files/Generation.h"
using namespace std;

// Prim_W, Prim_P create_EvolutionFunction(PrimEvolutionSetting& p_primEvolutionSetting){
//     return Prim_W(p_primEvolutionSetting), Prim_P(p_primEvolutionSetting);
// }

GuidedByHO0_W::GuidedByHO0_W(){}

GuidedByHO0_W::GuidedByHO0_W(PrimEvolutionSetting& p_primEvolutionSetting){
    E = p_primEvolutionSetting.get_E();
    m = p_primEvolutionSetting.get_m();
    w = p_primEvolutionSetting.get_w();
    b = p_primEvolutionSetting.get_b();
    evolution_stepSize = p_primEvolutionSetting.get_evolution_stepSize();
}

double GuidedByHO0_W::sourceSinkTerm(double& p_x_n, int& p_n){
    return b * pow(p_x_n, 4);
}

double GuidedByHO0_W::operator() (double& p_x_n, int& p_n){
    return exp(-evolution_stepSize * (sourceSinkTerm(p_x_n, p_n) - E));
}

void GuidedByHO0_W::opt(double& p_portionToAccept, Generation* p_generation){
    double averageSourceSinkTerm = 0;
    double* x_n = p_generation->get_x_n();
    for(int i = 0; i < p_generation->get_length_x_n(); i++){
        averageSourceSinkTerm += sourceSinkTerm(x_n[i], p_generation->generationNum);
    }
    averageSourceSinkTerm /= p_generation->get_length_x_n();
    E = log(p_portionToAccept)/evolution_stepSize + averageSourceSinkTerm;
    cout << "opt in gen " << p_generation->generationNum << " with E opt to " << E << endl;
}

GuidedByHO0_P::GuidedByHO0_P(){}

GuidedByHO0_P::GuidedByHO0_P(PrimEvolutionSetting& p_primEvolutionSetting){
    m = p_primEvolutionSetting.get_m();
    w = p_primEvolutionSetting.get_w();
    evolution_stepSize = p_primEvolutionSetting.get_evolution_stepSize();
    sigma = evolution_stepSize * (1- evolution_stepSize * w) / m;
}

double GuidedByHO0_P::driftTerm(double& p_x_n, int& p_n){
    return - evolution_stepSize * w * p_x_n;
}

stack<double>* GuidedByHO0_P::operator() (double& p_x_n, int& p_n, int& p_toGenerateNum){
	stack<double>* x_nPlus1 = new stack<double>;
	std::normal_distribution<double> gen_x_nPlus1{ p_x_n + driftTerm(p_x_n, p_n),sigma };
	for(int i = 0; i < p_toGenerateNum; ++i){
		(*x_nPlus1).push(gen_x_nPlus1(gen));
	}
	return x_nPlus1;
}

