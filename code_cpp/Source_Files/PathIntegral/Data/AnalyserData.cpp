#include <PathIntegral/Data/AnalyserData.h>
#include <cmath>
#include<Eigen/Eigenvalues>

// private:

long double AnalyserData::calc_moment_one(double* p_values){
    double toreturn = 0;
    for(int i = 0; i < num_of_values; i++){
        toreturn += p_values[i];
    }
    return toreturn / num_of_values;
}


long double AnalyserData::calc_mixed_moment_two(double* p_values1, double*p_values2){
    double toreturn = 0;
    for(int i = 0; i < num_of_values; i++){
        toreturn += p_values1[i] * p_values2[i];
    }
    return toreturn / num_of_values;
}

// public:

AnalyserData::AnalyserData(int p_num_of_values, int p_num_of_points){
    num_of_values = p_num_of_values;
    num_of_points = p_num_of_points;
    tau = new double[num_of_points];
    value = new double[num_of_points];
    std_value = new double[num_of_points];
    cov_value.resize(num_of_points, num_of_points);
    cout << "cov_value.size() " << cov_value.size() << endl;
    energies_groundState_maxEvo = new double[num_of_points];
}

AnalyserData::~AnalyserData(){
    for(auto it = values.begin(); it != values.end(); it++){
        delete[] *it;
    }
    values.empty();
}

void AnalyserData::add_pair(int p_index, double p_tau, double* p_values){
    tau[p_index] = p_tau;
    values.push_back(p_values);
}

void AnalyserData::add_energy_gs_maxEvo(int p_index, double p_energy){
    energies_groundState_maxEvo[p_index] = p_energy;
}

void AnalyserData::calc_energy_gs_maxEvo(void){
    double moment_one = calc_moment_one(energies_groundState_maxEvo);
    double moment_two = calc_mixed_moment_two(energies_groundState_maxEvo, energies_groundState_maxEvo);

    energy_groundState_maxEvo = moment_one;
    std_energy_groundState_maxEvo = pow(1./(num_of_values - 1) * (moment_two - pow(moment_one, 2)), 0.5);
}

void AnalyserData::calc_value(void){
    for(int i = 0; i < num_of_points; i++){
        for(int j = 0; j <= i; j++){
            if(i == j){
                cov_value(i, j) = (calc_mixed_moment_two(values[i], values[j]) - calc_moment_one(values[i]) * calc_moment_one(values[j])) / (num_of_values - 1);
            }
            else{
                cov_value(i, j) = 0;
                cov_value(j, i) = 0;
            }
            // cov_value(i, j) = double((calc_mixed_moment_two(values[i], values[j]) - calc_moment_one(values[i]) * calc_moment_one(values[j])) / (num_of_values - 1));
            // cov_value(j, i) = cov_value(i, j);
        }
        // cov_value(i, i) = (calc_mixed_moment_two(values[i], values[i]) - calc_moment_one(values[i]) * calc_moment_one(values[i])) / (num_of_values - 1);
        cout << "cov_value(" << i << "," << i << ") " << cov_value(i, i) << endl;
 

        value[i] = calc_moment_one(values[i]);
        std_value[i] = pow(cov_value(i, i), 0.5);
    }
     cov_value(0, 0) =  abs((calc_mixed_moment_two(values[0], values[0]) - calc_moment_one(values[0]) * calc_moment_one(values[0])) / (num_of_values - 1));
}

void AnalyserData::print_all_data(void){
    cout << "--------------analyser data----------------" << endl;
    cout << "tau \t | \t value \t | \t std_value \t" << endl; 
    cout << "-------------------------------------------" << endl;
    for(int i = 0; i < num_of_points; i++){
        cout << tau[i] << " \t | \t ";
        cout << value[i] << " \t";
        cout << " | \t ";
        cout << std_value[i] << " \t";
        cout << endl;
    }
    // cout << "-----------------cov_value--------------------" << endl;
    // cout << cov_value << endl;
    cout << "-------------------------------------------" << endl;
    cout << "GS energy through max Evo: " << energy_groundState_maxEvo << " +- " << std_energy_groundState_maxEvo << endl;
    cout << endl << endl;
}

void AnalyserData::print_values_of_generation(int p_index) {
    cout << "----------values of generation " << p_index <<"------------" << endl;
    for(int i = 0; i < num_of_values; i++){
        cout << values[p_index][i] << " ; ";
    }
    cout << endl << endl;
}