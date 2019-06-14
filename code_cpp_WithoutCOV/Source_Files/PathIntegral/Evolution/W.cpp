#include <iostream>
#include <stack>
#include <random>
#include <PathIntegral/Evolution/W.h>
using namespace std;

// 
// W
// 

W::W() {}

W::W(Setting& p_setting){
    E = p_setting.get_E();
    evolution_stepSize = p_setting.get_evolution_stepSize();
}

double W::weight(double& p_x, int& p_n) {return 0;}

double W::operator() (double& p_x_n, int& p_n) {
    return exp(-evolution_stepSize * (weight(p_x_n, p_n) - E));
}

void W::opt(double& p_portionToAccept, Generation* p_generation){
    double averageWeight = 0;
    for(int i = 0; i < p_generation->get_length_x_n(); i++){
        averageWeight += weight((*p_generation)[i], p_generation->generationNum);
    }
    averageWeight /= p_generation->get_length_x_n();
    E = log(p_portionToAccept)/evolution_stepSize + averageWeight;
    // cout << "opt in gen " << p_generation->generationNum << " with E opt to " << E << endl;
}

double& W::get_evolution_stepSize(){
    return evolution_stepSize;
}

double& W::get_E(){
    return E;
}

//
// Prim_W
//

Prim_W::Prim_W(){}

Prim_W::Prim_W(Setting& p_setting, double (*p_potential)(double p_x, double* p_pot_param)) : W(p_setting){
    pot_param = p_setting.get_pot_param();
    potential = p_potential;
}

double Prim_W::weight(double& p_x, int& p_n){
    return potential(p_x, pot_param);
    // return 0.5* m* pow(w, 2)* pow(p_x, 2) + b * pow(p_x, 4);
}

// 
// GuidedByHO0_W
// 

// GuidedByHO0_W::GuidedByHO0_W() {}

// GuidedByHO0_W::GuidedByHO0_W(Setting& p_setting) : W(p_setting){
//     b = (*(p_setting.get_param()))[2];
// }

// double GuidedByHO0_W::weight(double& p_x_n, int& p_n){
//     return b * pow(p_x_n, 4);
// }
