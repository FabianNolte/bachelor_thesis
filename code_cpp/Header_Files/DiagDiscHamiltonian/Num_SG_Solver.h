#pragma once

#include<iostream>
#include<Eigen/Dense>
#include<vector>

using namespace std;
using namespace Eigen;

class Num_SG_Solver {
    private:
        int matrix_size;
        double step_size;
        double boundary; 

        MatrixXd disc_hamiltonian;
        vector <double> eigenvalues;

        double m;
        double (*potential)(double, double*);
        double* param_potential;

        double PI;

        void construct_disc_hamiltonian(void);
        // construct_disc_hamiltonian - calculates the matrix entries for the discreizised hamiltionian

        void calculate_eigenvalues(void);
        // calculate_eigenvalues - calculates the eigenvalues of the dicretizised hamiltonian

    public:
        Num_SG_Solver(int p_step_num, double p_boundary, double(*p_potential)(double, double*), double* p_param_potential);
        // Num_SG_Solver - constructor
        // @param int p_step_num - number of steps to discretesize on
        // @param doulbe p_boundary - containing the minimal / maximal x value of the area to regard
        // @param double(*p_potential)(double, double*) - physical potential
        // @param double* p_param_potential - parameter for the physical potential

        void run(void);
        // run - runs the analysis with the given parameter

        void print_hamiltonian(void);
        // print_hamiltionian - prints hamiltonian in the console

        void print_eigenvalues(void);
        // print_eigenvalues - prints eigenvalues in the console
};