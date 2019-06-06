#pragma once

#include <vector>
#include <iostream>

#include <Eigen/Dense>
using namespace std;
using namespace Eigen;


class AnalyserData {
    private:
        vector<double*> values;
        double* energies_groundState_maxEvo;
        int num_of_values;
        
        long double calc_moment_one(double* p_values);
        // calc_moment - calculates the first moment of a given list 
        // @param double* p_values - list to perform on
        // @return double - calculated value
        
        long double calc_mixed_moment_two(double* p_values1, double*p_values2);
        // calc_moment - calculates the second mixed moment of two given lists
        // @param double* p_values1 - first list to perform on
        // @param double* p_values2 - second list to perform on
        // @return double - calculated value

    public:
        double* tau;
        double* value;
        double* std_value;
        MatrixXd cov_value;
        int num_of_points;

        double energy_groundState_maxEvo;
        double std_energy_groundState_maxEvo;

        AnalyserData(int p_num_of_values, int p_num_of_points);
        // AnalyserData - constructor
        // @param int p_num_of_values - number of values for each point
        // @param int p_num_of_points - number of points to regard

        ~AnalyserData();
        // ~AnalyserData - destructor
        // TODO add some lists to delete

        void add_pair(int p_index, double p_tau, double* p_values);
        // add_pair - adds new data point
        // @param int p_index - index to put point to
        // @param double p_tau - tau of the datapoint
        // @param p_values - list of values corresponding to the datapoint

        void add_energy_gs_maxEvo(int p_index, double p_energy);
        // TODO doc

        void calc_energy_gs_maxEvo(void);
        // TODO doc

        void calc_value(void);
        // calc_value - calculated value and their covariance matrix

        void print_all_data(void);
        // print_all_data - prints all points contained

        void print_values_of_generation(int p_index);
        // print_values_of_generation - prints all values corresponding to one generation
        // @param int p_index - index of the generation
};