#include <iostream>
#include <fstream>
#include <string>
#include "../Header_Files/EvolutionMemory.h"
using namespace std;

// TODO give values as reference
// TODO destructor

EvolutionMemory::EvolutionMemory(EvolutionSetting* p_setting, Generation* p_generation_0){
    setting = p_setting;
    generations.insert(pair<int, Generation*>(0, p_generation_0));
}

void EvolutionMemory::add_generation(Generation* p_generation){
    generations.insert(pair<int, Generation*>((*p_generation).generationNum, p_generation));
}

Generation* EvolutionMemory::get_generation(int p_generationNum){
    if (generations.count(p_generationNum) == 0)
    {
        cout << "generation does not exists yet" << endl;
        return nullptr;
    }
    else{
        return generations.find(p_generationNum)->second;
    }
}

EvolutionMemory::~EvolutionMemory(){
    for(auto i = generations.begin(); i != generations.end(); i++){
        delete i->second;   
    }
}

void EvolutionMemory::print_savedGenerations(void){
    cout << endl << endl;
    cout << "-------currently saved generations-------" << endl;
    for(auto i = generations.begin(); i != generations.end(); i++){
        cout << i->first << " , ";   
    }
    cout << endl << endl;
}
		// print_savedGenerations - prints all currently saved generations

void EvolutionMemory::save_generation(int p_generationNum, string p_path, string p_dataname){
	ofstream x_n_savefile;
	x_n_savefile.open(p_path + "/" + p_dataname + ".txt");
    double* x_n = (*EvolutionMemory::get_generation(p_generationNum)).get_x_n();
    int length_x_n = (*EvolutionMemory::get_generation(p_generationNum)).get_length_x_n();
    
    // cout << "EvolutionMemory::save_generation" << endl;
    // cout << &length_x_n << endl;
    // cout << *&length_x_n << endl;

	for (int i = 0; i<length_x_n; ++i){
		x_n_savefile << x_n[i] << endl;
	}
	cout << p_path + "/" + p_dataname + ".txt" << endl;
	x_n_savefile.close();
}

void EvolutionMemory::save_allGenerations(string p_path){
    for(auto i = generations.begin(); i != generations.end(); i++){
        ofstream x_n_savefile;
        x_n_savefile.open(p_path + "/gen" + to_string(i->first) + ".txt");
        double* x_n = (*(i->second)).get_x_n();
        int length_x_n = (*(i->second)).get_length_x_n();

        // cout << "EvolutionMemory::save_allGenerations" << endl;
        // cout << &length_x_n << endl;
        // cout << *&length_x_n << endl;

        for (int i = 0; i<length_x_n; ++i){
            x_n_savefile << x_n[i] << endl;
        }
        cout << p_path + "/gen" + to_string(i->first) + ".txt" << endl;
        x_n_savefile.close();
    }
    
}
		