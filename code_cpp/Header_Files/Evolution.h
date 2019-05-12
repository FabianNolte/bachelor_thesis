#pragma once
#include <string>
#include <random>
#include "EvolutionMemory.h"
#include "EvolutionSetting.h"
#include "EvolutionFunction.h"
#include "Generation.h"
using namespace std;

template<class temp_W, class temp_P>
class EvolutionExecuter
{
	private:
		EvolutionMemory* evolutionMemory;

		vector<int>* generationToCalc;

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

		int calc_replicationNumFor_x_n(double x_n);
		// calc_replicationNumFor_x_n - calculates according to the weight function the replication number of the current element
		// @param double x_n - x_n to calculate the replication number for

	public:
		// TODO without Prim
		EvolutionExecuter(EvolutionMemory& p_evolutionMemory, temp_W& p_W_x_n, temp_P& P_x_n_to_x_nPlus1, vector<int>& p_generationToCalc);
		// EvolutionExecuter - consturctor
		// @param EvolutionMemory* p_evolutionMemory - storage for the evolution
		// @param temp_W& p_W_x_n - object which calculates the weight
		// @param temp_P& P_x_n_to_x_nPlus1 - object which calculates P
		// @param vector<int>& p_generationToCalc - containing W and P to for the evolution
		
		void run(void);
		// run - rises the evolution of x_0
};






// class PrimEvolutionWithEOpt : public EvolutionExecuter
// {
// 	private:
// 		PrimEvolutionSettingWithEOpt* setting;

// 	private:
// 		void optE(void);
// 		// optE - optimizes E to achive constant generation size

// 	public:
// 		PrimEvolutionWithEOpt(EvolutionMemory* p_evolutionMemory, PrimEvolutionSettingWithEOpt* p_setting, EvolutionFunction* p_evoltuionFunction, std::mt19937 p_gen);
// 		// PrimEvolutionWithEOpt - consturctor
// 		// @param EvolutionMemory* p_evolutionMemory - storage for the evolution
// 		// @param PrimEvolutionSettingWithEOpt* p_setting - settings specifing how to carry out the evolution
//     	// @param EvolutionFunction* p_evoltuionFunction - containing W and P to for the evolution
//     	// @param std::mt19937 p_gen - random number generato

// 		void run(void);
// 		// run - rises the evolution of x_0



#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <vector>


//
// EvolutionExecuter
//

template<class temp_W, class temp_P>
EvolutionExecuter<temp_W, temp_P>::EvolutionExecuter(EvolutionMemory& p_evolutionMemory, temp_W& p_W_x_n, temp_P& p_P_x_n_to_x_nPlus1, vector<int>& p_generationToCalc){
	evolutionMemory = &p_evolutionMemory;
	W_x_n = &p_W_x_n;
	P_x_n_to_x_nPlus1 = &p_P_x_n_to_x_nPlus1;
	generationToCalc = &p_generationToCalc;
	replicationNum = 0;
}



template<class temp_W, class temp_P>
void EvolutionExecuter<temp_W, temp_P>::run(){
	// TODO maybe statrgeneration point calc and then use; faster
    for(vector<int>::iterator it = generationToCalc->begin(); it != --(generationToCalc->end()); it++){
		stack<double> stack_x_n_toSave;

		for(int i = 0; i < (evolutionMemory->get_generation(*it))->get_length_x_n(); ++i) {
			evolution_executer((evolutionMemory->get_generation(*it))->get_x_n()[i], *it , *(it+1), stack_x_n_toSave);
			cout << "finished with x_1_i = " << i << " at generation " << *(it+1) << endl;
		}

		Generation* x_n_toSave = new Generation(&stack_x_n_toSave, *(it+1));
		evolutionMemory->add_generation(x_n_toSave);
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
		int replicationNumFor_x_n = calc_replicationNumFor_x_n(x_n);

		if(replicationNumFor_x_n != 0) {
			replicationNum += replicationNumFor_x_n;
			//calc x_nPlus1 according to P with multipicity according to W
			stack<double>* x_nPlus1 = (*P_x_n_to_x_nPlus1)(x_n, replicationNumFor_x_n);
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
int EvolutionExecuter<temp_W, temp_P>::calc_replicationNumFor_x_n(double x_n){
	int replicationNumFor_x_n;
	double W = (*W_x_n)(x_n);
	replicationNumFor_x_n = int(W); // TODO check modulo ; faster
	std::uniform_real_distribution<double> d_accept(0, 1);
	if(d_accept(gen) <= W-replicationNumFor_x_n){
		++replicationNumFor_x_n;
	}
	return replicationNumFor_x_n;
}


// };
