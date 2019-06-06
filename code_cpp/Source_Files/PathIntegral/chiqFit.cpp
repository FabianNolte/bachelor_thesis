#include <iostream>
#include <cmath>
#include <TMinuit.h>
#include <TDataType.h>
#include <PathIntegral/chiqFit.h>
#include <Eigen/Eigenvalues>
using namespace std;

ChiqFit* currentChiqFit;

void nonMember_calc_chiq(int &npar, double *gin, double &f, double *par, int iflag){
    //cout << "1: " << f << endl;
    currentChiqFit->calc_chiq(npar, gin, f, par, iflag);
    //cout << "2: " << f << endl;
}

//
// Model
//

Model::Model(double (*p_fnc)(double*, int, double))//, 
            //double (*p_diff_fnc)(double*, int, double)=nullptr)
{
    fnc = p_fnc;
    //diff_fnc = p_diff_fnc;
}

//
//  RealData
//

RealData::RealData(int p_pointNum, 
                double* p_x, 
                double* p_y,
                MatrixXd& p_cov_y)
{
    pointNum = p_pointNum;
    x = p_x;
    y = p_y;

    // cout << "RD eigevalues of cov_y " << endl << p_cov_y.eigenvalues() << endl;
    // cout << "RD  cov_y " << endl << p_cov_y << endl;
    // double inv_min_cov_y = 1;
    // inv_min_cov_y /= p_cov_y.minCoeff();
    // inv_cov_y = (p_cov_y * inv_min_cov_y).inverse();
    inv_cov_y = p_cov_y.inverse();
    // cout << "RD eigevalues of inv_cov_y " << endl << inv_cov_y.eigenvalues() << endl;
    // cout << "RD  inv_cov_y " << endl << inv_cov_y << endl;
    // cout << "wait ";
    // cin.get();
    cout << endl;
}

void RealData::pprint(void)
{
    cout.precision(16);

    cout << "----------------Real Data------------------" << endl;
    cout << "x \t | \t y \t " << endl;
    cout << "-------------------------------------------" << endl;
    for(int i = 0; i < pointNum; i++){
        cout << x[i] << " \t | \t ";
        cout << y[i] << " \t || \t ";
        cout << endl;
    }
    // cout << "----------------inv_cov_y :-----------------" << endl;
    // cout << inv_cov_y << endl;
    // cout << "------------------cov_y :-------------------" << endl;
    // cout << inv_cov_y.inverse() << endl;
    

    cout << endl << endl;
}

//
// Output
//

Output::Output(double* p_beta, 
            double* p_sbeta, 
            string* p_beta_label,
            int p_len_beta,
            double p_chiq, 
            double p_chiqPndf,
            int p_ndf,
            double p_chiqProb)
{
    beta = p_beta;
    sbeta = p_sbeta;
    beta_label = p_beta_label;
    len_beta = p_len_beta;
    chiq = p_chiq;
    chiqPndf = p_chiqPndf;
    ndf = p_ndf;
    chiqProb = p_chiqProb;
}

void Output::pprint(void){
    cout << "----------------------------------------------------------Output-----------------------------------------------------------" << endl;
    cout << "label \t \t | \t beta \t | \t sbeta \t || \t chiq \t | \t chiqPndf \t | \t ndf \t | \t chiqProb \t" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << beta_label[0] << " \t | \t " << beta[0] << " \t | \t " << sbeta[0] << " \t || \t " << chiq << " \t | \t " << chiqPndf << " \t | \t " << ndf << " \t | \t " << chiqProb << " \t" << endl;
    for(int i = 1; i < len_beta; i++){
        cout << beta_label[i] << " \t | \t " << beta[i] << " \t | \t " << sbeta[i] << endl;
    }
    cout << endl << endl;
}

//
// ChiqFit
//

ChiqFit::ChiqFit(RealData& p_data, 
                Model& p_model,
                string* p_paramLabel,
                double* p_beta0,
                double* p_sbeta0,
                int p_len_beta0)
{
    data = &p_data;
    model = &p_model;
    paramLabel = p_paramLabel;
    beta0 = p_beta0;
    sbeta0 = p_sbeta0;
    len_beta0 = p_len_beta0;
    currentChiqFit = this;
}

void ChiqFit::calc_chiq(int &npar, double *gin, double &f, double *par, int iflag)
{
    MatrixXd y_dev(data->pointNum, 1);
    for(int i = 0; i < data->pointNum; i++){
        y_dev(i, 0) = data->y[i]-model->fnc(par, npar, data->x[i]);
    }  
    // cout << "inv_cov_y " << data->inv_cov_y << endl;
    MatrixXd chiq = y_dev.transpose() * data->inv_cov_y * y_dev;
    // cout << "chiq.size() " << chiq.size() << endl;
    cout << "chiq " << chiq(0, 0) << endl;
    f = chiq(0,0);

    // double chiq2 = 0;
    // for(int i = 0; i < data->pointNum; i++){
    //     chiq2 += pow((data->y[i]-model->fnc(par, npar, data->x[i])), 2) * data->inv_cov_y(i, i);
    //     // cout << "inv_cov_y(" << i << "," << i << ") " << data->inv_cov_y(i, i) << endl;
    // }  
    // cout << "chiq2 " << chiq2 << endl;
    // f = chiq2;
}


Output ChiqFit::run(void)
{
    // TMinuit minuit();
    minuit = new TMinuit(len_beta0);
    minuit->SetFCN(nonMember_calc_chiq);
    double arglist[10];
    int ierflg = 0;

    for(int i = 0; i < len_beta0;){
        // TODO restictions implementation is not general and ugly
        minuit->mnparm(i, paramLabel[i].c_str(), beta0[i], sbeta0[i], 0, 0, ierflg); //, 0.000000001, 1, ierflg);
        minuit->mnparm(i+1, paramLabel[i+1].c_str(), beta0[i+1], sbeta0[i+1], 0, 0, ierflg);
        i+=2;
    }

    minuit->SetPrintLevel(0);

    arglist[0]=1;
    minuit->mnexcm("SET ERR", arglist, 1, ierflg);

    // arglist[0] = 0.0001;
    // minuit->mnexcm("SET EPS", arglist, 1, ierflg);

    arglist[0]=1;
    minuit->SetMaxIterations(500);  
    minuit->Migrad();

    // minuit->mnexcm("CALL FCN", arglist, 1, ierflg);
    double* beta = new double[len_beta0];
    double* sbeta = new double[len_beta0];
    int len_beta = len_beta0;

    double chiq;
    double chiqPndf;
    int ndf;
    double chiqProb;

    for(int i = 0; i < len_beta0; i++){
        minuit->GetParameter(i,beta[i],sbeta[i]);
    }

    calc_chiq(len_beta, nullptr, chiq, beta, 0);
    ndf = data->pointNum - len_beta;
    chiqPndf = chiq/ndf;
    chiqProb = -1;

    Output output(beta, sbeta, paramLabel, len_beta, chiq, chiqPndf, ndf, chiqProb);

    return output;
}