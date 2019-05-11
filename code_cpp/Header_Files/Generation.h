#pragma once
#include <string>
#include <stack>
using namespace std;


class Generation{
    private:
    public:
        double* x_n;
        int length_x_n;
        int generationNum;
        string generationLable;

        Generation();
        // Generation - constructor

        Generation(stack<double>* p_x_n, int p_generationNum);
        // Generation - constructor
        // @param stack<double>* p_x_n - stackpointer for x_n values
        // @param int p_generationNum - number of the generation 

        double* get_x_n(void);
        // get_x_n - getter function for x_n
        // @return - pointer on array with values of x_n
        
        int get_length_x_n(void);
        // get_length_x_n - getter function for length_x_n
        // @return - length of x_n
};