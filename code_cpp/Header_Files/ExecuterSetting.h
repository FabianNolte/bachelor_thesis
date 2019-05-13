#pragma once
#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;


class ExecuterSetting
{
    private:
        map<int, pair<bool, bool>> generationToCalc;
    public:
        ExecuterSetting(vector<int>& generationToSave, vector<int>& generationToOpt);
        // ExecuterSetting - constructor
        // @param vector<int>& generationToSave - generations to be saved
        // @param vector<int>& generationToOpt - generations to optimize

        map<int, pair<bool, bool>>& get_generationToCalc(void);
        // get_generationToCalc - getter function for generationToCalc
        // @return map<int, pair<bool, bool>>& - reference of generationToCalc

        void print(void);
        // print - prints executer settings
};

