#include <PathIntegral/Data/AnalyserData.h>
#include <cmath>

AnalyserData::AnalyserData(int p_num_of_values, int p_num_of_points){
    num_of_values = p_num_of_values;
    num_of_points = p_num_of_points;
    tau = new double[num_of_points];
    value = new double[num_of_points];
    std_value = new double[num_of_points];
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

    double moment_one = calc_moment(1, p_values);
    double moment_two = calc_moment(2, p_values);

    value[p_index] = moment_one;
    std_value[p_index] = pow(1./(num_of_values - 1) * (moment_two - pow(moment_one, 2)), 0.5);
}

void AnalyserData::add_energy_gs_maxEvo(int p_index, double p_energy){
    energies_groundState_maxEvo[p_index] = p_energy;
}

void AnalyserData::calc_energy_gs_maxEvo(void){
    double moment_one = calc_moment(1, energies_groundState_maxEvo);
    double moment_two = calc_moment(2, energies_groundState_maxEvo);

    energy_groundState_maxEvo = moment_one;
    std_energy_groundState_maxEvo = pow(1./(num_of_values - 1) * (moment_two - pow(moment_one, 2)), 0.5);
}

double AnalyserData::calc_moment(int p_index, double* p_values){
    double toreturn = 0;
    for(int i = 0; i < num_of_values; i++){
        toreturn += pow(p_values[i], p_index);
    }
    return toreturn / num_of_values;
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