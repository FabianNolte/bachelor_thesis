#include <cmath>
#include <random>
#include "../Header_Files/StartFunction.h"
using namespace std;

double StartFunction::operator() (double& p_x){
	return 0;
}

Generation* StartFunction::calc_startingGeneration(const double* p_sampleArea, const double& p_numberOfPoints){
	std::random_device rd{};
	std::mt19937 gen{ rd() };

	stack<double>* x_0 = new stack<double>;
	std::uniform_real_distribution<double> d_x_i(p_sampleArea[0], p_sampleArea[1]);
	std::uniform_real_distribution<double> d_accept(0, max_startFunction);
	for (int i = 0; i < p_numberOfPoints;) {
		double x_0_i = d_x_i(gen);
		double accept_theshold = d_accept(gen);
		if ((*this)(x_0_i) >= accept_theshold) {
			(*x_0).push(x_0_i);
			++i;
		}
		
	}
    Generation* generation_0 = new Generation(x_0, 0, 1);
    return generation_0;
}



StartFunctionHO0::StartFunctionHO0(const double& p_m, const double& p_w){
    m = p_m;
    w = p_w;
    max_startFunction = pow(m * w / PI, 0.25);
}

double StartFunctionHO0::operator() (double& p_x){
	// return max_startFunction;
	return pow(m * w / PI, 0.25)* exp(-0.5 * m * w * pow(p_x, 2));
}