#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#include "../../Header_Files/Evolution/EvolutionExecuter.h"

//
// EvolutionExecuter
//

EvolutionExecuter::EvolutionExecuter(Memory& p_Memory, W* p_W_x_n, P* p_P_x_n_to_x_nPlus1, ExecuterSetting& p_ex_setting){
	memory = &p_Memory;
	W_x_n = p_W_x_n;
	P_x_n_to_x_nPlus1 = p_P_x_n_to_x_nPlus1;
	ex_setting = &p_ex_setting;
	replicationNum = 0;
}

void EvolutionExecuter::run(){

	// TODO maybe statrgeneration point calc and then use; faster
	Generation* gen_nMinus1 = memory->get_generation(0);
	// Generation* gen_n;

	int length_x_0 = gen_nMinus1->get_length_x_n();

	// TODO delete unsaved generation !!
	auto it_nMinus1 = ex_setting->get_generationToCalc().begin();
    for(auto it_n = ++(ex_setting->get_generationToCalc().begin()); it_n != (ex_setting->get_generationToCalc().end()); it_n++, it_nMinus1++){
		int nMinus1_genNum = gen_nMinus1->generationNum;
		double nMinus1_totalControlFactor = gen_nMinus1->get_totalControlFactor();
		
		if(((it_nMinus1)->second).second){
			double portionToAccept = double(length_x_0)/gen_nMinus1->get_length_x_n();
			int numOfGenToEvolve = it_n->first - nMinus1_genNum;
			double portionToAcceptEveryGen = pow(portionToAccept, 1.0/numOfGenToEvolve);
			W_x_n->opt(portionToAcceptEveryGen, gen_nMinus1);
		}
 		stack<double> stack_x_n;

		for(int i = 0; i < gen_nMinus1->get_length_x_n(); ++i) {
			evolution_executer((*gen_nMinus1)[i], nMinus1_genNum , it_n->first, stack_x_n);
		}
		// cout << "finished generation " << it_n->first << " with " << stack_x_n.size() << " points" << endl;

		if((it_nMinus1->second).first){
			memory->add_generation(gen_nMinus1);
		}
		else{
			delete gen_nMinus1;
		}
		gen_nMinus1 = new Generation(&stack_x_n, it_n->first, (it_n->first-nMinus1_genNum) * W_x_n->get_evolution_stepSize() + nMinus1_totalControlFactor);
	}
	if(((it_nMinus1)->second).first){
		memory->add_generation(gen_nMinus1);
	}
	else{
		delete gen_nMinus1;
	}

	memory->set_guessedGroundstateEnergy(W_x_n->get_E());
}


void EvolutionExecuter::evolution_executer(double x_n, int n, int max_n, stack<double>& stack_x_n_toSave)
{
	if(n == max_n){
		//add to result stack
		stack_x_n_toSave.push(x_n);
	}

	else{
		//calc multipicity accorting to W
		int replicationNumFor_x_n = calc_replicationNumFor_x_n(x_n, n);

		if(replicationNumFor_x_n != 0) {
			replicationNum += replicationNumFor_x_n;
			//calc x_nPlus1 according to P with multipicity according to W
			stack<double>* x_nPlus1 = (*P_x_n_to_x_nPlus1)(x_n, n, replicationNumFor_x_n);
			//call evolution_executer for all x_nPlus1
			for(int i=0; i < replicationNumFor_x_n; ++i){
				evolution_executer((*x_nPlus1).top(), n+1, max_n, stack_x_n_toSave);
				(*x_nPlus1).pop();
			}
			delete x_nPlus1;
		}
	}
}

// TODO pass to function per reference ; faster
int EvolutionExecuter::calc_replicationNumFor_x_n(double x_n, int p_n){
	int replicationNumFor_x_n;
	double W = (*W_x_n)(x_n, p_n);
	replicationNumFor_x_n = int(W); // TODO check modulo ; faster
	std::uniform_real_distribution<double> d_accept(0, 1);
	if(d_accept(gen) <= W-replicationNumFor_x_n){
		++replicationNumFor_x_n;
	}
	return replicationNumFor_x_n;
}

