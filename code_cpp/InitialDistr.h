#pragma once
#include <string>
#include <random>
using namespace std;


class InitialDistr
{
	private:
		double* x_1;
		int length_x_1;
        const double* sampleArea;
        double (*Phi)(double); 
		double maxPhi;
		std::mt19937 gen;

	public:
		InitialDistr(std::mt19937 p_gen);
		// InitialDistr - constructor
		// @param std::mt19937 p_gen - random number generator

		~InitialDistr();
		// ~InitialDistr - deletes array x_1

		void generate_x_val(int p_length_x_1, const double* p_sampleArea, double (*p_Phi)(double), double p_maxPhi);
		// generate_x_val - uses Neumann rejection to generate the x_1 distribution according to Phi
        // @param int p_length_x_1 - amount of x_1 to be generated
        // @param double* p_sampleArea - array of the Area to sample on (first entry left border; second entry right border)
        // @param double (*p_Phi)(double) - function to sample
        // @param double p_maxPhi - maximal value of the function which is supposed to be sampled

		double* get_x_1(void);
		// get_x_1 - getter function for x_1
		// @return double* - addres of x_1 double array (located on heap)

		int get_length_x_1(void);
		// get_length_x_1 - getter function for length_x_1
		// @return int - number of elements in x_1

		void print_x_1_sampleArea(void);
		// print_x_1_sampleArea - print the sample Area of x_1

		void save_x_1(string  folder, string  name);
		// save_x_1 - saves x_1 into a txt-file 
		// @param string folder - folder location to save to
		// @param string name - dataname to save to

};