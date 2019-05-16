#pragma once
#include <string>
#include <random>
#include "EvolutionMemory.h"
#include "EvolutionSetting.h"
#include "PrimEvolutionFunction.h"
#include "Generation.h"
#include "ExecuterSetting.h"
using namespace std;

template<class temp_W, class temp_P>
class EvolutionExecuter
{
	private:
		EvolutionMemory* evolutionMemory;

		ExecuterSetting* ex_setting;

		temp_W* W_x_n;
		temp_P* P_x_n_to_x_nPlus1;
		
		int replicationNum;

        std::random_device rd{};
        std::mt19937 gen{ rd() };

		void evolution_executer(double x_n, int n, int max_n, stack<double>& stack_x_N);
		// evolution_executer - calculates recursivly the evolution of one x_0_i
		// @param double x_n - x_n to evolute
		// @param int n - starting generation
		// @param in max_n - generation to evolve to
		// @param stack<double>& - saving structur for elements of the last generation

		int calc_replicationNumFor_x_n(double x_n, int p_n);
		// calc_replicationNumFor_x_n - calculates according to the weight function the replication number of the current element
		// @param double x_n - x_n to calculate the replication number for
		// @param int p_n - number of generation 

	public:
		// TODO without Prim
		EvolutionExecuter(EvolutionMemory& p_evolutionMemory, temp_W& p_W_x_n, temp_P& P_x_n_to_x_nPlus1, ExecuterSetting& p_ex_setting);
		// EvolutionExecuter - consturctor
		// @param EvolutionMemory* p_evolutionMemory - storage for the evolution
		// @param temp_W& p_W_x_n - object which calculates the weight
		// @param temp_P& P_x_n_to_x_nPlus1 - object which calculates P
		// @param ExecuterSetting& p_ex_setting- TODO
		
		void run(void);
		// run - rises the evolution of x_0
};









#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>


//
// EvolutionExecuter
//

template<class temp_W, class temp_P>
EvolutionExecuter<temp_W, temp_P>::EvolutionExecuter(EvolutionMemory& p_evolutionMemory, temp_W& p_W_x_n, temp_P& p_P_x_n_to_x_nPlus1, ExecuterSetting& p_ex_setting){
	evolutionMemory = &p_evolutionMemory;
	W_x_n = &p_W_x_n;
	P_x_n_to_x_nPlus1 = &p_P_x_n_to_x_nPlus1;
	ex_setting = &p_ex_setting;
	replicationNum = 0;
}



template<class temp_W, class temp_P>
void EvolutionExecuter<temp_W, temp_P>::run(){


	// TODO maybe statrgeneration point calc and then use; faster
	Generation* gen_nMinus1 = evolutionMemory->get_generation(0);
	// Generation* gen_n;

	int length_x_0 = gen_nMinus1->get_length_x_n();

	// TODO delete unsaved generation !!
	auto it_nMinus1 = ex_setting->get_generationToCalc().begin();
    for(auto it_n = ++(ex_setting->get_generationToCalc().begin()); it_n != (ex_setting->get_generationToCalc().end()); it_n++, it_nMinus1++){
		if(((it_nMinus1)->second).second){
			double portionToAccept = double(length_x_0)/gen_nMinus1->get_length_x_n();
			int numOfGenToEvolve = it_n->first - gen_nMinus1->generationNum;
			double portionToAcceptEveryGen = pow(portionToAccept, 1.0/numOfGenToEvolve);
			cout << "portionToAcceptEveryGen = " << portionToAcceptEveryGen << endl;
			W_x_n->opt(portionToAcceptEveryGen, gen_nMinus1);
		}
 		stack<double> stack_x_n;

		for(int i = 0; i < gen_nMinus1->get_length_x_n(); ++i) {
			evolution_executer(gen_nMinus1->get_x_n()[i], gen_nMinus1->generationNum , it_n->first, stack_x_n);
		}
		cout << "finished generation " << it_n->first << " with " << stack_x_n.size() << " points" << endl;

		if((it_nMinus1->second).first){
			evolutionMemory->add_generation(gen_nMinus1);
		}
		else{
			delete gen_nMinus1;
		}
		gen_nMinus1 = new Generation(&stack_x_n, it_n->first);
	}
	if(((it_nMinus1)->second).first){
		evolutionMemory->add_generation(gen_nMinus1);
	}
	else{
		delete gen_nMinus1;
	}
}





template<class temp_W, class temp_P>
void EvolutionExecuter<temp_W, temp_P>::evolution_executer(double x_n, int n, int max_n, stack<double>& stack_x_n_toSave)
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
template<class temp_W, class temp_P>
int EvolutionExecuter<temp_W, temp_P>::calc_replicationNumFor_x_n(double x_n, int p_n){
	int replicationNumFor_x_n;
	double W = (*W_x_n)(x_n, p_n);
	replicationNumFor_x_n = int(W); // TODO check modulo ; faster
	std::uniform_real_distribution<double> d_accept(0, 1);
	if(d_accept(gen) <= W-replicationNumFor_x_n){
		++replicationNumFor_x_n;
	}
	return replicationNumFor_x_n;
}


// };
