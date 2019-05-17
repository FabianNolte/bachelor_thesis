#include <iostream>
#include <TRandom1.h>

int main(void){
	TRandom1* myrand = new TRandom1();
	for(int i =0; i<10; ++i){
		std::cout << myrand->Gaus(5,1) << std::endl;
	}
	return 0;
}
