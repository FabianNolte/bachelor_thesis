#pragma once
#include <TRandom1.h>
using namespace std;

class Analyser{
    private:
        double x;
        TRandom1* myrand;
    public:
        Analyser(double p_x);
        void print(void);
};