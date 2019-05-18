#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include "../../Header_Files/Evolution/ExecuterSetting.h"
using namespace std;

ExecuterSetting::ExecuterSetting(vector<int>& p_generationToSave, vector<int>& p_generationToOpt){
    sort(p_generationToSave.begin(), p_generationToSave.end());

    if(!p_generationToOpt.empty()){
        sort(p_generationToOpt.begin(), p_generationToOpt.end());

        auto it_save = p_generationToSave.begin();
        auto it_opt = p_generationToOpt.begin();

        auto it_save_end = --p_generationToSave.end();
        auto it_opt_end = --p_generationToOpt.end();

        while(*it_opt < *it_save) it_opt++;
        while(*it_opt_end > *it_save_end) it_opt_end--;

        while(it_save != p_generationToSave.end()){
            pair<bool, bool> boolPair;
            int genNum;
            if(*it_save < *it_opt){
                boolPair.first = true;
                boolPair.second = false;
                genNum = *it_save;
                it_save ++;
            }
            else if(*it_save == *it_opt){
                boolPair.first = true;
                boolPair.second = true;
                genNum = *it_save;
                it_save ++;
                it_opt ++;
            }
            else if(*it_save > *it_opt){
                boolPair.first = false;
                boolPair.second = true;
                genNum = *it_opt;
                it_opt ++;
            }
            pair<int, pair<bool, bool>> pairToInsert(genNum, boolPair);
            generationToCalc.insert(pairToInsert);
        }
    }
    else{
        for(auto it_save = p_generationToSave.begin(); it_save != p_generationToSave.end(); it_save++){
            pair<bool, bool> boolPair(true, false);
            pair<int, pair<bool, bool>> pairToInsert(*it_save, boolPair);
            generationToCalc.insert(pairToInsert);
        }
    }
}

map<int, pair<bool, bool>>& ExecuterSetting::get_generationToCalc(void){
    return generationToCalc;
}

void ExecuterSetting::print(){
    cout << "----------executer Setting-----------" << endl;
    cout << "genNum \t | \t save \t | \t opt \t" << endl; 
    cout << "-------------------------------------" << endl;
    for(auto it = generationToCalc.begin(); it != generationToCalc.end(); it++){
        cout << it->first << " \t | \t ";
        (it->second).first ? cout << "x \t" : cout << "\t";
        cout << " | \t ";
        (it->second).second ? cout << "x \t" : cout << "\t"; 
        cout << endl;
    }
    cout << endl << endl;

}
