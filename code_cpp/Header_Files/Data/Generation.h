#pragma once
#include <string>
#include <stack>
using namespace std;

// TODO Generation[] operator
class Generation{
    private:
        double* x_n;
        int length_x_n;
        double totalControlFactor;
        string savePosition;
        string plotPosition;
    public:
        int generationNum;

        Generation();
        // Generation - constructor

        Generation(stack<double>* p_x_n, int p_generationNum, double p_totalControlFactor);
        // Generation - constructor
        // @param stack<double>* p_x_n - stackpointer for x_n values
        // @param int p_generationNum - number of the generation 
        // @param double p_totalControlFactor - additianal multiplicative factor according to the optimization which fixes the number of points in every generation

        ~Generation(void);
        // ~Generation - destructor, deletes x_n

        double& operator[] (int p_i);
        // operator[] - returns the x_n_i position
        // @param int p_i - number of the element to return
        // @return double& - position x_n_i

        void set_savePosition(string p_savePosition);
        // set_savePosition - sets the position of the .txt file the generation is saved to
        // @param string p_savePosition - position to set

        void set_plotPosition(string p_plotPosition);
        // set_plotPosition - sets the position of the .pdf file the generation is ploted to
        // @param string p_plotPosition - position to set
        
        int get_length_x_n(void);
        // get_length_x_n - getter function for length_x_n
        // @return - length of x_n

        int get_totalControlFactor(void);
        // totalControlFactor - getter function for totalControlFactor
        // @return - totalControlFactor
};