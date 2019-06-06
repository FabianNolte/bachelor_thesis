#pragma once
#include <string>
#include <stack>
using namespace std;

// TODO Generation[] operator
class Generation{
    private:
        double* x_n;
        int length_x_n;
        double normFactor_n;
        double std_normFactor_n;
        double totalControlFactor;
        string savePosition;
        string plotPosition;
    public:
        int generationNum;

        Generation();
        // Generation - constructor

        Generation(double* p_x_n, int p_length_x_n, double& p_normFactor_n, double& p_std_normFactor_n, int p_generationNum, double p_totalControlFactor);
        // Generation - constructor
        // @param double* p_x_n - array for x_n values
        // @param int p_length_x_n - number of x_n values
        // @param double& p_normFacotr_n - normalization factor of the distribution
        // @param double& p_std_normFacotr_n - empirical error on the normalization factor
        // @param int p_generationNum - number of the generation 
        // @param double p_totalControlFactor - additianal multiplicative factor according to the optimization which fixes the number of points in every generation

        ~Generation(void);
        // ~Generation - destructor, deletes x_n

        double& operator[] (int p_i);
        // operator[] - returns the x_n_i position
        // @param int p_i - number of the element to return
        // @return double& - position x_n_i

        double* get_x_n(void);
        // TODO doc

        void set_savePosition(string p_savePosition);
        // set_savePosition - sets the position of the .txt file the generation is saved to
        // @param string p_savePosition - position to set

        void set_plotPosition(string p_plotPosition);
        // set_plotPosition - sets the position of the .pdf file the generation is ploted to
        // @param string p_plotPosition - position to set
        
        int get_length_x_n(void);
        // get_length_x_n - getter function for length_x_n
        // @return - length of x_n

        double& get_normFactor_n(void);
        // get_normFacotr_n - getter function for normFacotr_n
        // @return - normFacotr_n

        double& get_std_normFactor_n(void);
        // get_std_normFacotr_n - getter function for std_normFacotr_n
        // @return - std_normFacotr_n

        double& get_totalControlFactor(void);
        // totalControlFactor - getter function for totalControlFactor
        // @return double& - totalControlFactor
};