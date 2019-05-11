#pragma once
#include <string>
#include <map>
#include "EvolutionSetting.h"
#include "Generation.h"
using namespace std;


class EvolutionMemory{
	private: 
        	map<int, Generation*> generations;
			map<int, string> saveFiles; 

	public:
	        EvolutionSetting* setting;

		EvolutionMemory();
		// EvolutionSetting - consturctor

		EvolutionMemory(EvolutionSetting* p_setting, Generation* p_generation_0);
		// EvolutionSetting - consturctor
		// @param EvolutionSetting* p_setting - settings specifing how to carry out the evolution
		// @param Generation* p_generation_0 - starting values

		void add_generation(Generation* p_generation);
		// add_generation - adds p_generation to generations
		// @param Generation* p_generation - generation to add

		Generation* get_generation(int p_generationNum);
		// get_generation - getter function for a generation
		// @param int p_generationNum - number of the generation to get
		// @return Generation* - pointer on generation

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
};











