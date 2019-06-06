#include <PathIntegral/Data/Setting.h>
#include <PathIntegral/Data/MemoryWrapper.h>

#include <PathIntegral/Evolution/EvolutionOrganizer.h>
#include <PathIntegral/Evolution/EvolutionExecuter.h>
#include <PathIntegral/Evolution/ExecuterSetting.h>

#include <iostream>
using namespace std;



EvolutionOrganizer::EvolutionOrganizer(MemoryWrapper& p_memoryWrapper, Generation* p_generation0, Setting& p_setting, ExecuterSetting& p_executerSetting){
    memoryWrapper = &p_memoryWrapper;
    executerSetting = &p_executerSetting;
    setting = &p_setting;

    for(int i = 0; i < setting->get_num_of_memories(); i++){
        Memory* memory_to_add = new Memory(p_generation0);
        memoryWrapper->add_memory(memory_to_add);
    }
}

void EvolutionOrganizer::run_allEvolutions(void){
    for(int i = 0; i < setting->get_num_of_memories(); i++){
        cout << endl << "evolution of memory " << i << endl << endl;
        EvolutionExecuter evolutionExecuter((*memoryWrapper)[i], executerSetting);
        evolutionExecuter.run();
    }
}