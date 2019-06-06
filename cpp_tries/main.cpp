#include <iostream>

#include <Eigen/Dense>
#include <Eigen/LU>

using namespace std;
using namespace Eigen;

int main(){
    int size = 4;

    MatrixXd m(size,size);

    MatrixXd v(size,1);

    for(int i = 0; i < size; i++){
        cout << i << endl; 
        m(i, i) = i+1;
        v(i, 0) = i;
    }

    cout << m << endl;
    cout << m.inverse() << endl;

    cout << v.transpose() << endl;

    cout << v.transpose()*m*v << endl;

    MatrixXd res = v.transpose()*m*v;
    double res_double = res(0,0);

    cout << "res " << res(0,0) << endl;
    cout << "res dob " << res_double << endl;
}

