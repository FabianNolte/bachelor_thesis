#include<iostream>
#include<Eigen/Dense>
#include<Eigen/Eigenvalues>
#include<cmath>
#include<vector>
#include<DiagDiscHamiltonian/Num_SG_Solver.h>
using namespace std;
using namespace Eigen;

Num_SG_Solver::Num_SG_Solver(int p_step_num, double p_boundary, double(*p_potential)(double, double*), double* p_param_potential){
    matrix_size = p_step_num;
    boundary = p_boundary;
    step_size = 2*p_boundary/(matrix_size);
    potential = p_potential;
    param_potential = p_param_potential;
    disc_hamiltonian.resize(p_step_num, p_step_num);
    m = 1;
    PI = 3.141592653589793238463;
}

void Num_SG_Solver::construct_disc_hamiltonian(void){
    // for(int i_loop = 0; i_loop < matrix_size; i_loop++){
    //     disc_hamiltonian(i_loop, i_loop) = i_loop;
    // }
    int n = (matrix_size -1)/2;
    double k_step_size = 2*PI/((matrix_size) * step_size);

    for(int i_loop = -n; i_loop <= n; i_loop++){
        for(int j_loop = -n; j_loop <= n; j_loop++){
            double potential_energy = 0;
            double kinetic_energy = 0;
            if(i_loop == j_loop){
                potential_energy = potential(i_loop * step_size, param_potential);
            }
            for(int l_loop = 1; l_loop <= n; l_loop++){
                kinetic_energy += cos(l_loop * 2 * PI * (i_loop - j_loop) / (matrix_size)) * pow(l_loop, 2);
            }
            kinetic_energy *= pow(k_step_size, 2) / ((matrix_size) * m);
            disc_hamiltonian(i_loop + n, j_loop + n) = (kinetic_energy + potential_energy); // / step_size;
        }
        // cout << "i_loop " << i_loop << endl;
    }
}

void Num_SG_Solver::run(void){
    construct_disc_hamiltonian();
    calculate_eigenvalues();
}

void Num_SG_Solver::print_hamiltonian(void){
    // for (auto it = eigenvalues.begin(); it != eigenvalues.end(); it++) {
    //     cout << *it << " ";
    //     cout << endl; 
    // }
    cout << endl << disc_hamiltonian << endl << endl;
}

void Num_SG_Solver::calculate_eigenvalues(void){
    EigenSolver<MatrixXd> es(disc_hamiltonian);
    Matrix<complex<double>, -1, 1> eigenvalues_matrix = es.eigenvalues();
    
    for(int i_loop = 0; i_loop < matrix_size; i_loop++){
        eigenvalues.push_back(complex<double>(eigenvalues_matrix[i_loop]).real());
    }
    sort(eigenvalues.begin(), eigenvalues.end());
}

void Num_SG_Solver::print_eigenvalues(void){
    cout << "---------------eigenvalues---------------" << endl;
    for(vector<double>::iterator it = eigenvalues.begin(); it != eigenvalues.end(); it++){
        cout << *it  << " ; ";
    }
    cout << endl;
}