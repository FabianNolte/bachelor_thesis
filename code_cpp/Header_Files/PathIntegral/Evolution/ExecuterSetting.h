#pragma once
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <PathIntegral/Evolution/P.h>
#include <PathIntegral/Evolution/W.h>
using namespace std;


class ExecuterSetting
{
    private:
        map<int, pair<bool, bool>> generationToCalc;
        W* w_func;
        P* p_func;

    public:
        ExecuterSetting(vector<int>& generationToSave, vector<int>& generationToOpt, W* p_w_func, P* p_p_func);
        // ExecuterSetting - constructor
        // @param vector<int>& generationToSave - generations to be saved
        // @param vector<int>& generationToOpt - generations to optimize
		// @param W* p_w_func - object which calculates the weight
		// @param P* p_p_func - object which calculates P

        map<int, pair<bool, bool>>& get_generationToCalc(void);
        // get_generationToCalc - getter function for generationToCalc
        // @return map<int, pair<bool, bool>>& - reference of generationToCalc

        W* get_w_func(void);
        // get_w_func - getter function for w_func
        // @return W* - pointer on w_func

        P* get_p_func(void);
        // get_p_func - getter function for p_func
        // @return P* - pointer on p_func

        void print(void);
        // print - prints executer settings
};

