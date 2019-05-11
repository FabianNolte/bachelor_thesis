#pragma once
#include <string>
#include <random>
using namespace std;


class InitialDistr
{
	private:
		stack<double>* x_0;
		int length_x_0;
        const double* sampleArea;
        double (*Phi)(double); 
		double maxPhi;
		std::mt19937 gen;

	public:
		InitialDistr(std::mt19937 p_gen);
		// InitialDistr - constructor
		// @param std::mt19937 p_gen - random number generator

		void generate_x_val(int p_length_x_0, const double* p_sampleArea, double (*p_Phi)(double), double p_maxPhi);
		// generate_x_val - uses Neumann rejection to generate the x_0 distribution according to Phi
        // @param int p_length_x_0 - amount of x_0 to be generated
        // @param double* p_sampleArea - array of the Area to sample on (first entry left border; second entry right border)
        // @param double (*p_Phi)(double) - function to sample
        // @param double p_maxPhi - maximal value of the function which is supposed to be sampled

		stack<double>* get_x_0(void);
		// get_x_0 - getter function for x_0
		// @return stack<double>* - addres of x_0 double stack (located on heap)

		int get_length_x_0(void);
		// get_length_x_0 - getter function for length_x_0
		// @return int - number of elements in x_0

		void print_x_0_sampleArea(void);
		// print_x_0_sampleArea - print the sample Area of x_0

};