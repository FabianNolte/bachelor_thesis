#include <cmath>
#include <iostream>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TFrame.h>
#include <TObject.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <Eigen/Dense>

#include <PathIntegral/Analyser.h>
#include <PathIntegral/chiqFit.h>

#include <PathIntegral/Data/Generation.h>
using namespace std;
using namespace Eigen;



double fit_fcn(double* pam, int npam, double x){
    double toreturn = 0;
    for(int i = 0; i < npam; i+=2){
        toreturn += pam[i]*exp(- x*pam[i+1]);
    }
    return toreturn;
}

//
// Analyser
//

Analyser::Analyser(MemoryWrapper& p_memoryWrapper, Setting& p_setting, StartFunction& p_startFunction){
    memoryWrapper = &p_memoryWrapper;
    setting = &p_setting;
    startFunction = &p_startFunction;
    analyserData = new AnalyserData(p_memoryWrapper.get_num_of_memories(), p_memoryWrapper[0]->get_sizeGenerations());
}

Analyser::~Analyser(void){
    delete analyserData;
}

double Analyser::calc_moment(Generation* p_generation, int p_order){
    double toreturn = 0;
    for(int i = 0; i < p_generation->get_length_x_n(); i ++){
        toreturn += pow((*startFunction)((*p_generation)[i]), p_order);
    }
    return toreturn /(p_generation->get_length_x_n());
}

void Analyser::calc_value(void){}

void Analyser::print_data(void){
    analyserData->print_all_data();

    // analyserData->print_values_of_generation(0);
    // analyserData->print_values_of_generation(4);
    // analyserData->print_values_of_generation(9);
    
}

void Analyser::plot_data(string p_path){
    TCanvas* canvas = new TCanvas();   
    canvas->SetGrid();
    canvas->GetFrame()->SetFillColor(21);
    canvas->GetFrame()->SetBorderSize(12);
    double* std_tau = new double[analyserData->num_of_points];
    for(int i = 0; i < analyserData->num_of_points; i++){
        std_tau[i] = 0;
    }
  //  canvas->cd(1);
    
    TGraphErrors *g = new TGraphErrors(analyserData->num_of_points, analyserData->tau, analyserData->value, std_tau, analyserData->std_value);    
    g->SetTitle("TGraphErrors Example");
    g->SetMarkerColor(4);
   // g->SetMarkerStyle(21);
    g->Draw("ALP");
    g->Draw("p"); 
    string savePosition = p_path+"/analyserPlot.pdf";
    canvas->Print(savePosition.c_str());
    delete canvas;
    delete g;
}

void Analyser::fit_data(int p_NumOfEnergies, double p_minTau){
    cout << "jo" << endl;
    int pos_minTau = 0;
    while(analyserData->tau[pos_minTau] < p_minTau && pos_minTau < analyserData->num_of_points) pos_minTau++;

    int fit_dataNum = analyserData->num_of_points - pos_minTau;
    double fit_tau[fit_dataNum];
    double fit_std_tau[fit_dataNum];
    double fit_value[fit_dataNum];
    double fit_std_value[fit_dataNum];
    for(int i = 0; i < fit_dataNum; i++){
        fit_tau[i] = analyserData->tau[pos_minTau+i];
        fit_std_tau[i] = 0;
        fit_value[i] = analyserData->value[pos_minTau+i];
        fit_std_value[i] = analyserData->std_value[pos_minTau+i];
    }
    MatrixXd fit_cov_value = (analyserData->cov_value).block(pos_minTau, pos_minTau, fit_dataNum, fit_dataNum);

    cout << "vor alles mit fit chiq" << endl;

    RealData data(fit_dataNum, fit_tau, fit_value, fit_cov_value);
    Model model(fit_fcn);
    int len_beta0 = p_NumOfEnergies*2;
    double beta0[len_beta0];
    double sbeta0[len_beta0];
    string paramLabel[len_beta0];
    for(int i = 0; i < len_beta0; i+=2){
        beta0[i] = 0.5;
        beta0[i+1] = analyserData->energy_groundState_maxEvo * (i+1);
        sbeta0[i] = 0.1;
        sbeta0[i+1] = analyserData->std_energy_groundState_maxEvo;
        paramLabel[i] = "prefactor"+to_string(i/2);
        paramLabel[i+1] = "energy"+to_string(i/2);
    } 
    ChiqFit chiqFit(data, model, paramLabel, beta0, sbeta0, len_beta0);
    cout << "vor run" << endl;
    Output output = chiqFit.run();
    cout << "nach run" << endl;
    output.pprint();

    //TObject* tobject = chiqFit.minuit->GetPlot();
    // tobject->Print();

    // output.beta[0] = 0.858;
    // output.beta[1] = 2.0;
    // output.beta[2] = 1.5;
    // output.beta[3] = 6;

    double start_tau = fit_tau[0];
    double end_tau = fit_tau[fit_dataNum-1];
    const int cont_Num = 1000;
    double cont_tau[cont_Num];
    double cont_fit_value[cont_Num];
    cont_tau[0] = start_tau;
    cont_fit_value[0] = fit_fcn(output.beta, output.len_beta, cont_tau[0]);
    double tau_diff = (end_tau-start_tau)/cont_Num;
    for(int i = 1; i < cont_Num; i++){
        cont_tau[i] = cont_tau[i-1]+tau_diff;
        cont_fit_value[i] = fit_fcn(output.beta, output.len_beta, cont_tau[i]);
    }

    TCanvas* canvas = new TCanvas(); 
    canvas->Divide(1,2);  
    canvas->SetGrid();
    canvas->GetFrame()->SetFillColor(21);
    canvas->GetFrame()->SetBorderSize(12);
    TMultiGraph *mg = new TMultiGraph();
    mg->SetTitle("Exclusion graphs");

    TGraph *gr1 = new TGraph(cont_Num,cont_tau,cont_fit_value);
    gr1->SetLineColor(2);
    gr1->SetLineWidth(1504);
    gr1->SetFillStyle(3005);

    //gr1->Draw("ac");
    TGraphErrors *gr2 = new TGraphErrors(fit_dataNum,fit_tau,fit_value, fit_std_tau, fit_std_value);    
  
    gr2->SetTitle("TGraphErrors Example");
    gr2->SetMarkerColor(2);
    // gr2->SetMarkerStyle(21);
    // g->Draw();
    //gr2->Draw("ap");
    // g->Draw("p"); 

    mg->Add(gr1);
    mg->Add(gr2);

    canvas->cd(1);
    mg->Draw("ap");

    //
    //  Residuen
    //
    double res_tau[fit_dataNum];
    double res_std_tau[fit_dataNum];
    double res_value[fit_dataNum];
    double res_std_value[fit_dataNum];
    for(int i = 0; i < fit_dataNum; i++){
        res_tau[i] = fit_tau[i];
        res_std_tau[i] = 0;
        res_value[i] = fit_value[i] - fit_fcn(output.beta, output.len_beta, fit_tau[i]);
        res_std_value[i] = fit_std_value[i];
    }

    TGraphErrors *gr3 = new TGraphErrors(fit_dataNum,res_tau,res_value, res_std_tau, res_std_value);    
    gr3->SetTitle("residue");
    gr3->SetMarkerColor(2);

    canvas->cd(2);
    gr3->Draw("ap");
    // gr2->SetMarkerStyle(21);
    // g->Draw();
    //gr2->Draw("ap");
    // g->Draw("p"); 


    string savePosition = "fitPlot.pdf";
    canvas->Print(savePosition.c_str());
    delete canvas;
    // delete g;

    // cout << "cov_value " << endl << analyserData->cov_value << endl;
    // cout << "eigenvalues of cov_value " << endl << analyserData->cov_value.eigenvalues() << endl;;

    MatrixXd corr_value = analyserData->cov_value;
    for(int i = 0; i < analyserData->num_of_points; i++){
        for(int j = 0; j < analyserData->num_of_points; j++){
            corr_value(i, j) = corr_value(i,j) / pow(analyserData->cov_value(i, i) * analyserData->cov_value(j, j), 0.5);
        }
    }
    // cout << "corr_value " << endl << corr_value << endl;

}

//
// PrimAnalyser
//

PrimAnalyser::PrimAnalyser(MemoryWrapper& p_memoryWrapper, Setting& p_setting, StartFunction& p_startFunction) : Analyser(p_memoryWrapper, p_setting, p_startFunction){
    calc_value();
}

void PrimAnalyser::calc_value(void){
    int num_of_memories = memoryWrapper->get_num_of_memories();

    map<int, Generation*>::iterator its[num_of_memories];
    for(int i = 0; i < num_of_memories; i++){
        its[i] = ((*memoryWrapper)[i]->get_generations())->begin();
        analyserData->add_energy_gs_maxEvo(i, (*memoryWrapper)[i]->get_guessedGroundstateEnergy());
    }

    double evolution_stepSize = setting->get_evolution_stepSize();
    // int length_x_0 = generations->begin()->second->get_length_x_n();


    double moment_1;
    double moment_2;

    int generationNum = 0;
    int i = 0;
    while(its[0] != ((*memoryWrapper)[0]->get_generations())->end()){
        i++;
        double tau = its[0]->first * evolution_stepSize;
        double* values = new double[num_of_memories];
        for(int i = 0; i < num_of_memories; i++){

            moment_1 = calc_moment(its[i]->second, 1);
            moment_2 = calc_moment(its[i]->second, 2);
            double totalControlFactor_n =  its[i]->second->get_totalControlFactor();
            double normFactor_n = its[i]->second->get_normFactor_n();
            values[i] = totalControlFactor_n * moment_1 * normFactor_n;
            // cout << "moment_1 " << moment_1 << endl;
            // cout << "moment_2 " << moment_2 << endl;
            // cout << "totalControlFactor_n : " << totalControlFactor_n << endl;
            // double var_moment_1 = 1./(its[i]->second->get_length_x_n()) * abs(moment_2 - pow(moment_1, 2));
            // double var_normFactor_n = pow(its[i]->second->get_std_normFactor_n(),2);
            // std_value[i] = totalControlFactor_n * pow(normFactor_n * var_moment_1 + moment_1 * var_normFactor_n, 0.5);
            its[i]++;
        }

        analyserData->add_pair(generationNum, tau, values);
        generationNum++;
    }
    analyserData->calc_value();
    analyserData->calc_energy_gs_maxEvo();
}