#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <random>
#include <string>
#include <stack>
#include "InitialDistr.h"


InitialDistr::InitialDistr(std::mt19937 p_gen){
	gen = p_gen;
}

InitialDistr::~InitialDistr(){
	delete[] x_1;
}

// void InitialDistr::print_x_1_sampleArea(void)
// {
// 	std::cout << "\n begin: " << x_1_sampleArea[0] << "\n end: " << x_1_sampleArea[1];
// }

void InitialDistr::generate_x_val(int p_length_x_1, const double* p_sampleArea, double (*p_Phi)(double), double p_maxPhi)
{
    length_x_1 = p_length_x_1;
    sampleArea = p_sampleArea;
    Phi = p_Phi;
    maxPhi = p_maxPhi;
	x_1 = new double[length_x_1];
	std::uniform_real_distribution<double> d_x_i(sampleArea[0], sampleArea[1]);
	std::uniform_real_distribution<double> d_accept(0, maxPhi);
	for (int i = 0; i < length_x_1;) {
		double x_1_i = d_x_i(gen);
		double accept_theshold = d_accept(gen);
		if (Phi(x_1_i) >= accept_theshold) {
			x_1[i] = x_1_i;
			++i;
		}
		
	}
	//printArray(x_1, length_x_1);
}

double* InitialDistr::get_x_1(void) {
	return x_1;
}

int InitialDistr::get_length_x_1(void) {
	return length_x_1;
}

void InitialDistr::save_x_1(string  folder, string  name) {
	ofstream x_1_savefile;
	x_1_savefile.open(folder + name + ".txt");
	for (int i = 0; i<length_x_1; ++i){
		x_1_savefile << x_1[i] << endl;
	}
	x_1_savefile.close();
}