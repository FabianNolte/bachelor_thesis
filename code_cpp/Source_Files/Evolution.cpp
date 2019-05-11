#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <stack>
#include "../Header_Files/Evolution.h"
using namespace std;

Evolution::Evolution(EvolutionMemory* p_evolutionMemory, std::mt19937 p_gen){
	evolutionMemory = p_evolutionMemory;
	gen = p_gen;
	replicationNum = 0;
}

// Evolution::~Evolution(){
// 	delete[] x_N;
// }

void Evolution::run(){
	stack<int>* loc_generationToSave = (*(*evolutionMemory).setting).generationToSave;
	//if((*loc_generationToSave).top() == 0) {(*loc_generationToSave).pop();}
	Generation* startGeneration;
	while (!(*loc_generationToSave).empty()){
		// cout << "stacktop = " << (*loc_generationToSave).top() << endl; 	
		// cout << "stacksize = " << (*loc_generationToSave).size() << endl; 	
		startGeneration = (*evolutionMemory).get_generation((*loc_generationToSave).top());
		(*loc_generationToSave).pop();

		if(!(*loc_generationToSave).empty()){
			stack<double> stack_x_n_toSave;

			// cout << "startGeneration = " << startGeneration << endl; 

			for(int i = 0; i < (*startGeneration).get_length_x_n(); ++i) {
				evolution_executer((*startGeneration).get_x_n()[i], 1, (*loc_generationToSave).top(), stack_x_n_toSave);
				cout << "finished with x_1_i = " << i << " at generation " << (*loc_generationToSave).top() << endl;
			}

			Generation* x_n_toSave = new Generation(&stack_x_n_toSave, (*loc_generationToSave).top());
			(*evolutionMemory).add_generation(x_n_toSave);
		}
	}
}

void Evolution::evolution_executer(double x_n, int n, int max_n, stack<double>& stack_x_n_toSave)
{
	if(n == max_n){
		//add to result stack
		stack_x_n_toSave.push(x_n);
	}

	else{
		//calc multipicity accorting to W
		int replicationNumFor_x_n = calc_replicationNumFor_x_n(x_n);

		if(replicationNumFor_x_n != 0) {
			replicationNum += replicationNumFor_x_n;
			//calc x_nPlus1 according to P with multipicity according to W
			stack<double>* x_nPlus1 = (*(*evolutionMemory).setting).P_x_n_to_x_nPlus1(x_n, (*(*evolutionMemory).setting).evolution_stepSize, replicationNumFor_x_n);
			//call evolution_executer for all x_nPlus1
			for(int i=0; i < replicationNumFor_x_n; ++i){
				evolution_executer((*x_nPlus1).top(), n+1, max_n, stack_x_n_toSave);
				(*x_nPlus1).pop();
			}
			delete x_nPlus1;
		}
	}
		}

int Evolution::calc_replicationNumFor_x_n(double x_n){
	int replicationNumFor_x_n;
	double W = (*(*evolutionMemory).setting).W_x_n(x_n, (*(*evolutionMemory).setting).E, (*(*evolutionMemory).setting).evolution_stepSize);
	replicationNumFor_x_n = int(W);
	std::uniform_real_distribution<double> d_accept(0, 1);
	if(d_accept(gen) <= W-replicationNumFor_x_n){
		++replicationNumFor_x_n;
	}
	return replicationNumFor_x_n;
}

