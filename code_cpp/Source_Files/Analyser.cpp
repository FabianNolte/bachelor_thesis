#include <iostream>
#include "../Header_Files/Analyser.h"
using namespace std;

Analyser::Analyser(double p_x) {
    x = p_x; 
    myrand = new TRandom1();
}
void Analyser::print(){ 
    cout << x << "asdf "<< myrand->Gaus(5,1) << endl;
}