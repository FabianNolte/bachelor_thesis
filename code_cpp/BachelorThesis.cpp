
/**
    BachelorThesis.cpp
    Purpose: Numerical evaluation of first stats to a given potential using functional integrals

    @author Fabian Nolte
    @version 1.0 5/9/19 
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <stack>
#include "InitialDistr.h"
#include "Evolution.h"

using namespace std;

std::random_device rd{};
std::mt19937 gen{ rd() };

const double E = 0.5;
const double m = 1;
const double w = 1;
const double b = 0;

const double imgTime = 20;
const int numImgTimeSlices = 50;
const double x_1_sampleArea[2] = {-10, 10};
const int num_x_1 = 4000;

const double PI = 3.141592653589793238463;
//const double H_BAR = 
const double EPSILON = imgTime / numImgTimeSlices;
const double STD = pow(EPSILON / m, 0.5);

//Beginning function
const double max_givenPhi = pow(m * w / PI, 0.25);

double givenPhi(double x)
{
	return max_givenPhi;
	//return pow(m * w / PI, 0.25)* exp(-0.5 * m * w * pow(x, 2));
}


void runPyScr_plot_x_1(string path, string dataname, float left, float right, int histnum)
{
	string filename = "../code_python/plot_x_1.py";
	string command = "python ";
	string args = " " + path + " " + dataname + " " + to_string(left) + " " + to_string(right) + " "+ to_string(histnum);

	command += filename += args;
	cout << endl << command << endl;
	system(command.c_str());
}


double givenPotential(double x)
{
	return 0.5* m* pow(w, 2)* pow(x, 2) + b * pow(x, 4);
}

double givenW(double x_n, double E, double evolution_step)
{
	return exp(-evolution_step * (givenPotential(x_n) - E));
}

stack<double>* givenP(double x_n, double evolution_step, int toGenerateNum)
{
	double sigma = pow(evolution_step/m, 0.5);
	stack<double>* x_nPlus1 = new stack<double>;
	std::normal_distribution<double> gen_x_nPlus1{ x_n,sigma };
	for(int i = 0; i < toGenerateNum; ++i){
		(*x_nPlus1).push(gen_x_nPlus1(gen));
	}
	return x_nPlus1;
}






int main()
{
	std::cout.precision(50);

	InitialDistr inst_initialDistr(gen);
	// inst_initialDistr.print_x_1_sampleArea();
	inst_initialDistr.generate_x_val(num_x_1, x_1_sampleArea, givenPhi, max_givenPhi);
	double* x_1 = inst_initialDistr.get_x_1();
	int length_x_1 = inst_initialDistr.get_length_x_1();
	//printArray(x_1, num_x_1);
	inst_initialDistr.save_x_1("../data/", "x_1");
	runPyScr_plot_x_1("../data/", "x_1", x_1_sampleArea[0], x_1_sampleArea[1], 60);

	//!!!!!! x_1 will be deformed by inst_evolution !!!! ?
	Evolution inst_evolution(x_1, length_x_1, gen);
	inst_evolution.evolution_caller(numImgTimeSlices, EPSILON, E, givenW, givenP);
	cout << "vor save_x_N" << endl;
	inst_evolution.save_x_N("../data/", "x_N");
	runPyScr_plot_x_1("../data/", "x_N", x_1_sampleArea[0], x_1_sampleArea[1], 60);
}


//
// function definitions 
//



// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
