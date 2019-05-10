#pragma once
#include <string>
#include <random>
using namespace std;

class Evolution
{
	private:
		double* x_1;
		int length_x_1;

		double* x_N;
		int length_x_N;

		int evolution_stepNum;
		double evolution_step;
		double E;
		std::mt19937 gen;
		
		int replicationNum;

		double (*W_x_n)(double, double, double);
		stack<double>* (*P_x_n_to_x_nPlus1)(double, double, int);

		
		void evolution_executer(double x_n, int n, stack<double>& stack_x_N);
		// evolution_executer - calculates recursivly the evolution of one x_1_i
		// @param double - x_n to evolute
		// @param int - generation
		// @param stack<double>& - saving structur for elements of the last generation

		int calc_replicationNumFor_x_n(double x_n);
		// calc_replicationNumFor_x_n - calculates according to the weight function the replication number of the current element
		// @param double - x_n to calculate the replication number for

	public:
		Evolution(double*, int, std::mt19937 p_gen);
		// Evolution - consturctor
		// @param double* - addres of x_1 double array 
		// @param int - number of elements in x_1
        // @param std::mt19937 p_gen - random number generator

		~Evolution();
		// ~Evolution - deletes array x_N

		void evolution_caller(int p_evolution_stepNum, double p_evolution_step, double p_E, double (*p_W_x_n)(double, double, double), stack<double>* (*p_P_x_n_to_x_nPlus1)(double, double, int));
		// evolution_caller - rises the evolution of x_1
		// @param int - evolution steps to be made
		// @param double - evolution steplength
		// @param double - energieterm for controling
		// @param double (*fnc)(double, double, double) - weight function
		// @param stack<double>* (*fnc)(double, double, int) - function for generating the next evolution step

		double* get_x_N(void);
		// get_x_N - getter function for x_N
		// @return double* - addres of x_N double array (located on heap)

		int get_length_x_N(void);
		// get_length_x_N - getter function for length_x_N
		// @return int - number of elements in x_N

		void save_x_N(string , string);
		// save_x_N - saves x_N into a txt-file 
		// @param string - folder location to save to
		// @param string - dataname to save to
};
