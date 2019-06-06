#pragma once

#include <vector>
#include <iostream>
using namespace std;


class AnalyserData {
    private:
        vector<double*> values;
        double* energies_groundState_maxEvo;
        int num_of_values;
        
        double calc_moment(int p_index, double* p_values);
        // calc_moment - calculates the desired moment of a given list 
        // @param int p_index - order of the moment to calculate
        // @param double* p_values - list to perform on
        // @return double - calculated value

    public:
        double* tau;
        double* value;
        double* std_value;
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

        void print_all_data(void);
        // print_all_data - prints all points contained

        void print_values_of_generation(int p_index);
        // print_values_of_generation - prints all values corresponding to one generation
        // @param int p_index - index of the generation
};