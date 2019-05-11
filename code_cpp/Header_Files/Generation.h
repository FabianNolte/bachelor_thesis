#pragma once
#include <string>
#include <stack>
using namespace std;


class Generation{
    private:
        double* x_n;
        int length_x_n;
        string savePosition;
        string plotPosition;
    public:
        int generationNum;
        string generationLable;

        Generation();
        // Generation - constructor

        Generation(stack<double>* p_x_n, int p_generationNum);
        // Generation - constructor
        // @param stack<double>* p_x_n - stackpointer for x_n values
        // @param int p_generationNum - number of the generation 

        ~Generation(void);
        // ~Generation - destructor, deletes x_n

        void set_savePosition(string p_savePosition);
        // set_savePosition - sets the position of the .txt file the generation is saved to
        // @param string p_savePosition - position to set

        void set_plotPosition(string p_plotPosition);
        // set_plotPosition - sets the position of the .pdf file the generation is ploted to
        // @param string p_plotPosition - position to set

        double* get_x_n(void);
        // get_x_n - getter function for x_n
        // @return - pointer on array with values of x_n
        
        int get_length_x_n(void);
        // get_length_x_n - getter function for length_x_n
        // @return - length of x_n

        string get_savePosition(void);
        // get_savePosition - returns the position of the .txt file the generation is saved to
        // @return string - position of the .txt file

        string get_plotPosition(void);
        // get_plotPosition - returns the position of the .pdf file the generation is ploted to
        // @return string - position of the .pdf file
};