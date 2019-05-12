

//
// PrimEvolutionWithEOpt
//

// PrimEvolutionWithEOpt::PrimEvolutionWithEOpt(EvolutionMemory* p_evolutionMemory, PrimEvolutionSettingWithEOpt* p_setting, EvolutionFunction* p_evoltuionFunction, std::mt19937 p_gen) : EvolutionExecuter(p_evolutionMemory, p_evoltuionFunction, p_gen){
// }

// void PrimEvolutionWithEOpt::run(){
// 	vector<int> loc_generationToSave = (*setting).generationToSave;
// 	vector<int> loc_generationToOptE = (*setting).generationToOptE;

// 	map<int, pair<bool, bool>> generationToCalc; 

// 	for (int genNumToSave : loc_generationToSave){
// 		generationToCalc.insert(pair<genNumToSave, pair<true, false>>);
// 	}
// 	for (int genNumToOptE : loc_generationToOptE){
// 		vector<int>::iterator genNumToOptE_position = generationToCalc.find(genNumToOptE)
// 		if(genNumToOptE_position == generationToCalc.end()){
// 			generationToCalc.insert(pair<genNumToOptE, pair<false, true>>);
// 		}
// 		else{
// 			generationToCalc.erase(genNumToOptE)
// 			generationToCalc.insert(pair<genNumToOptE, pair<true, true>>);
// 		}
// 	}

// 	Generation* startGeneration;

//     for(map<int, pair<bool, bool>>::iterator it = generationToCalc.begin(); it != --(generationToCalc.end()); it++){
// 		startGeneration = (*evolutionMemory).get_generation(it->first);

// 		stack<double> stack_x_n_toSave;

// 		int endGenerationNum = (it+1)->first;

// 		for(int i = 0; i < (*startGeneration).get_length_x_n(); ++i) {
// 			evolution_executer((*startGeneration).get_x_n()[i], 1, endGenerationNum, stack_x_n_toSave);
// 			cout << "finished with x_1_i = " << i << " at generation " << endGenerationNum << endl;
// 		}

// 		Generation* x_n_toSave = new Generation(&stack_x_n_toSave, *(it+1));
// 		(*evolutionMemory).add_generation(x_n_toSave);
// 	}
// }
