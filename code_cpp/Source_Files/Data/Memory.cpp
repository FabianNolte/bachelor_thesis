#include <iostream>
#include <fstream>
#include <string>
#include "../../Header_Files/Data/Memory.h"
using namespace std;

//
//  Memory
//

// TODO give values as reference
// TODO destructor

Memory::Memory(Generation* p_generation_0){
    generations.insert(pair<int, Generation*>(0, p_generation_0));
}

void Memory::add_generation(Generation* p_generation){
    generations.insert(pair<int, Generation*>((*p_generation).generationNum, p_generation));
}

Generation* Memory::get_generation(int p_generationNum){
    if (generations.count(p_generationNum) == 0)
    {
        cout << "generation does not exists yet" << endl;
        return nullptr;
    }
    else{
        return generations.find(p_generationNum)->second;
    }
}

Memory::~Memory(){
    for(auto i = generations.begin(); i != generations.end(); i++){
        delete i->second;   
    }
}

void Memory::print_savedGenerations(void){
    cout << endl << endl;
    cout << "-------currently saved generations-------" << endl;
    for(auto i = generations.begin(); i != generations.end(); i++){
        cout << i->first << " , ";   
    }
    cout << endl << endl;
}

void Memory::save_generation(int p_generationNum, string p_path, string p_dataname){
	ofstream x_n_savefile;
    string filePosition = p_path + "/" + p_dataname + ".txt";
	x_n_savefile.open(filePosition);
    Generation* generationToSave = Memory::get_generation(p_generationNum);
    int length_x_n = generationToSave->get_length_x_n();

	for (int i = 0; i<length_x_n; ++i){
		x_n_savefile << (*generationToSave)[i] << endl;
	}
    cout << "generation " << p_generationNum << " saved to " << filePosition << endl;
	x_n_savefile.close();
    generationToSave->set_savePosition(filePosition);
}

void Memory::save_allGenerations(string p_path){
    for(auto i = generations.begin(); i != generations.end(); i++){
        ofstream x_n_savefile;
        string filePosition = p_path + "/gen" + to_string(i->first) + ".txt";
        x_n_savefile.open(filePosition);
        Generation* generationToBeSaved = (i->second);
        int length_x_n = (*generationToBeSaved).get_length_x_n();

        for (int i = 0; i<length_x_n; ++i){
            x_n_savefile << (*generationToBeSaved)[i] << endl;
        }
        cout << "generation " << i->first << " saved to " << filePosition << endl;
        x_n_savefile.close();
        generationToBeSaved->set_savePosition(filePosition);
    }
}

void Memory::plot_savedGenerations(string loc_pythonScript, string path, double left_border, double right_border, int histnum){
    for(auto i = generations.begin(); i != generations.end(); i++){
        string dataname = "gen" + to_string(i->first);
        string command = "python ";
        string args = " " + path + " " + dataname + " " + to_string(left_border) + " " + to_string(right_border) + " "+ to_string(histnum);
    
        command += loc_pythonScript + args;
        system(command.c_str());
        cout << "generation " << i->first << " ploted to " << path+"/"+dataname+".pdf" << endl;
        (*(i->second)).set_savePosition(path+"/"+dataname);
    }
}
	