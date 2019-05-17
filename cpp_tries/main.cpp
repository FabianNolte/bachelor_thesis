#include <iostream>
using namespace std;

class Base{
    protected:
        int a;
        int b;
    public:
        Base(){
        }

        Base(int p_a, int p_b){
            a = p_a;
            b = p_b;
        }

        void printSum(){
            cout << "base!" << endl;
        }
};

class Derived : public Base{
    private:
        int bias;
        int add(){
            return a + b + bias;
        }
    public:
        Derived(){}

        Derived(int p_a, int p_b, int p_bias) : Base(p_a, p_b){
            bias = p_bias;
        }

        void printSum(){
            cout << add() << endl;
        }

};


int main(){
    Base* derived = new Derived(1,2,3);
    derived->printSum();
}

