#pragma once
#include <string>
#include <random>
#include "EvolutionMemory.h"
#include "EvolutionSetting.h"
#include "Generation.h"
using namespace std;

class Evolution
{
	private:
		EvolutionMemory* evolutionMemory;
		std::mt19937 gen;
		
		int replicationNum;

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
		Evolution(EvolutionMemory* p_evolutionMemory, std::mt19937 p_gen);
		// Evolution - consturctor
		// @param EvolutionMemory* p_evolutionMemory - storage for the evolution
        // @param std::mt19937 p_gen - random number generator

		// ~Evolution();
		// // ~Evolution - deletes array x_N

		void run(void);
		// run - rises the evolution of x_0

};
