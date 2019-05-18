#include "../Header_Files/Analyser.h"

//
// Analyser
//

Analyser::Analyser(Memory& p_memory, Setting& p_setting, StartFunction& p_startFunction){
    memory = &p_memory;
    setting = &p_setting;
    startFunction = &p_startFunction;
}

void Analyser::calc_value(void){}

//
// PrimAnalyser
//

PrimAnalyser::PrimAnalyser(Memory& p_memory, Setting& p_setting, StartFunction& p_startFunction) : Analyser(p_memory, p_setting, p_startFunction){}

void PrimAnalyser::calc_value(void){
    dataNum = memory->get_sizeGenerations();
    tau = new double[dataNum];
    value = new double[dataNum];
    std_value = new double[dataNum];
    

}