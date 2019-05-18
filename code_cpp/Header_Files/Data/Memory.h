#pragma once
#include <string>
#include <map>
#include "Setting.h"
#include "Generation.h"
using namespace std;


class Memory{
	private: 
			// TODO maybe Generation insted of Generation* ? could be faster
        	map<int, Generation*> generations;
        	double guessedGroundstateEnergy;

	public:
		Memory();
		// Memory - consturctor

		Memory(Generation* p_generation_0);
		// Memory - consturctor
		// @param Generation* p_generation_0 - starting values

		~Memory();
		// ~Memory - destructor, deletes all generations

		void set_guessedGroundstateEnergy(double& p_guessedGroundstateEnergy);
		// set_guessedGroundstateEnergy - setter function for set_guessedGroundstateEnergy
		// @param double& p_set_guessedGroundstateEnergy - value to set

		double& get_guessedGroundstateEnergy(void);
		// get_guessedGroundstateEnergy - getter function for guessedGroundstateEnergy
		// @return double& - value of guessedGroundstateEnergy

		void add_generation(Generation* p_generation);
		// add_generation - adds p_generation to generations
		// @param Generation* p_generation - generation to add

		Generation* get_generation(int p_generationNum);
		// get_generation - getter function for a generation
		// @param int p_generationNum - number of the generation to get
		// @return Generation* - pointer on generation

		int get_sizeGenerations(void);
		// get_sizeGenerations - returns amount of storaged generations
		// @return int - size of generations

		void print_savedGenerations(void);
		// print_savedGenerations - prints all currently saved generations

		void save_generation(int p_generationNum, string p_path, string p_dataname);
		// save_generation - saves the x_n values of the given generation into a .txt file
		// @param int p_generationNum - number of generation to save
		// @param string p_path - path to save to
		// @param string p_dataname - dataname to give

		void save_allGenerations(string p_path);
		// save_allGeneration - saves the x_n values of all generations into .txt files
		// @param string p_path - path to save to

		void plot_savedGenerations(string loc_pythonScript, string path, double left_border, double right_border, int histnum);
		// plot_savedGenerations - creats histograms of all saved generations using a python script
		// @param loc_pythonScript - position of the python script to use
		// @param string path - path to save to
		// @param double left_border - left border of the visalization
		// @param double right_border - right border of the visalization
		// @param int histnum - number of bins in the histogram


		void plot_savedGenerations(double left_border, double right_border, int histnum);
		// plot_savedGenerations - creats histograms of all saved generations using a python script
		// @param double left_border - left border of the visalization
		// @param double right_border - right border of the visalization
		// @param int histnum - number of bins in the histogram


};
