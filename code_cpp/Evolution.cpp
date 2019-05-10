#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <stack>
#include "Evolution.h"
using namespace std;

Evolution::Evolution(double* p_x_1, int p_length_x_1, std::mt19937 p_gen){
	x_1 = p_x_1;
	length_x_1 = p_length_x_1;
	replicationNum = 0;
	gen = p_gen;
}

Evolution::~Evolution(){
	delete[] x_N;
}

void Evolution::evolution_caller(int p_evolution_stepNum, double p_evolution_step, double p_E, double (*p_W_x_n)(double, double, double), stack<double>* (*p_P_x_n_to_x_nPlus1)(double, double, int)){
	evolution_stepNum = p_evolution_stepNum;
	evolution_step = p_evolution_step;
	W_x_n = p_W_x_n;
	P_x_n_to_x_nPlus1 = p_P_x_n_to_x_nPlus1;
	E = p_E;
	stack<double> stack_x_N;
	for(int i = 0; i < length_x_1; ++i) {
		evolution_executer(x_1[i], 1, stack_x_N);
		cout << "finished with x_1_i = " << i << endl;
	}
	length_x_N = stack_x_N.size();
	x_N = new double[length_x_N];
	for(int i = 0; i < length_x_N; ++i) {
		x_N[i] = stack_x_N.top();
		stack_x_N.pop();
	}
}

void Evolution::evolution_executer(double x_n, int n, stack<double>& stack_x_N)
{
	if(n == evolution_stepNum){
		//add to result stack
		stack_x_N.push(x_n);
	}

	else{
		//calc multipicity accorting to W
		int replicationNumFor_x_n = calc_replicationNumFor_x_n(x_n);

		if(replicationNumFor_x_n != 0) {
			replicationNum += replicationNumFor_x_n;
			//calc x_nPlus1 according to P with multipicity according to W
			stack<double>* x_nPlus1 = P_x_n_to_x_nPlus1(x_n, evolution_step, replicationNumFor_x_n);
			//call evolution_executer for all x_nPlus1
			for(int i=0; i < replicationNumFor_x_n; ++i){
				evolution_executer((*x_nPlus1).top(), n+1, stack_x_N);
				(*x_nPlus1).pop();
			}
			delete x_nPlus1;
		}
	}
		}

int Evolution::calc_replicationNumFor_x_n(double x_n){
	int replicationNumFor_x_n;
	double W = W_x_n(x_n, E, evolution_step);
	replicationNumFor_x_n = int(W);
	std::uniform_real_distribution<double> d_accept(0, 1);
	if(d_accept(gen) <= W-replicationNumFor_x_n){
		++replicationNumFor_x_n;
	}
	return replicationNumFor_x_n;
}

double* Evolution::get_x_N(void) {
	return x_N;
}

int Evolution::get_length_x_N(void) {
	return length_x_N;
}

void Evolution::save_x_N(string  folder, string  name) {
	ofstream x_N_savefile;
	x_N_savefile.open(folder + name + ".txt");
	for (int i = 0; i<length_x_N; ++i){
		x_N_savefile << x_N[i] << endl;
	}
	cout << folder + name + ".txt" << endl;
	x_N_savefile.close();
}