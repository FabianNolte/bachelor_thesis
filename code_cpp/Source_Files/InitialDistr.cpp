#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <random>
#include <string>
#include <stack>
#include "../Header_Files/InitialDistr.h"


// InitialDistr::InitialDistr(){
// }


// void InitialDistr::print_x_0_sampleArea(void)
// {
// 	std::cout << "\n begin: " << x_0_sampleArea[0] << "\n end: " << x_0_sampleArea[1];
// }

void InitialDistr::generate_x_val(int p_length_x_0, const double* p_sampleArea, double (*p_Phi)(double), double p_maxPhi)
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };

    length_x_0 = p_length_x_0;
    sampleArea = p_sampleArea;
    Phi = p_Phi;
    maxPhi = p_maxPhi;
	x_0 = new stack<double>;
	std::uniform_real_distribution<double> d_x_i(sampleArea[0], sampleArea[1]);
	std::uniform_real_distribution<double> d_accept(0, maxPhi);
	for (int i = 0; i < length_x_0;) {
		double x_0_i = d_x_i(gen);
		double accept_theshold = d_accept(gen);
		if (Phi(x_0_i) >= accept_theshold) {
			(*x_0).push(x_0_i);
			++i;
		}
		
	}
	//printArray(x_0, length_x_0);
}

stack<double>* InitialDistr::get_x_0(void) {
	return x_0;
}

int InitialDistr::get_length_x_0(void) {
	return length_x_0;
}
