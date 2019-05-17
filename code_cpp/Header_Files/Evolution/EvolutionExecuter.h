#pragma once
#include <string>
#include <random>
#include "../Data/Memory.h"
#include "../Data/Generation.h"
#include "../Data/Setting.h"
#include "P.h"
#include "W.h"
#include "ExecuterSetting.h"
using namespace std;

class EvolutionExecuter
{
	private:
		Memory* memory;

		ExecuterSetting* ex_setting;

		W* W_x_n;
		P* P_x_n_to_x_nPlus1;
		
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
		EvolutionExecuter(Memory& p_Memory, W* p_W_x_n, P* P_x_n_to_x_nPlus1, ExecuterSetting& p_ex_setting);
		// EvolutionExecuter - consturctor
		// @param Memory* p_Memory - storage for the evolution
		// @param W* p_W_x_n - object which calculates the weight
		// @param P* P_x_n_to_x_nPlus1 - object which calculates P
		// @param ExecuterSetting& p_ex_setting- TODO
		
		double run(void);
		// run - rises the evolution of x_0
		// @return - estimator for ground state energie
};

