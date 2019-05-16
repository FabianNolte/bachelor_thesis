
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
#include <vector>
#include "../Header_Files/InitialDistr.h"
#include "../Header_Files/Evolution.h"
#include "../Header_Files/PrimEvolutionFunction.h"
#include "../Header_Files/EvolutionSetting.h"
#include "../Header_Files/EvolutionMemory.h"
#include "../Header_Files/Generation.h"
#include "../Header_Files/ExecuterSetting.h"
#include "../Header_Files/GuidedEvolutionFunction.h"

using namespace std;

const double E = 2;
const double m = 1;
const double w = 4;
const double b = 0.5;

const double imgTime = 0.25;
const int numImgTimeSlices = 60;
const double x_0_sampleArea[2] = {-10, 10};
const int num_x_0 = 10000;

const double plotArea[2] = {-10, 10};
const int histnum = 250;

const double PI = 3.141592653589793238463;
//const double H_BAR = 
const double EPSILON = imgTime / numImgTimeSlices;
const double STD = pow(EPSILON / m, 0.5);

//Beginning function
const double max_givenPhi = pow(m * w / PI, 0.25);

double givenPhi(double x)
{
	//return max_givenPhi;
	return pow(m * w / PI, 0.25)* exp(-0.5 * m * w * pow(x, 2));
}





void runPyScr_plot_x_0(string path, string dataname, float left, float right, int histnum)
{
	string filename = "../code_python/plot_x_0.py";
	string command = "python ";
	string args = " " + path + " " + dataname + " " + to_string(left) + " " + to_string(right) + " "+ to_string(histnum);

	command += filename += args;
	cout << endl << command << endl;
	system(command.c_str());
}




int main()
{
	std::cout.precision(50);

	InitialDistr inst_initialDistr;
	inst_initialDistr.generate_x_val(num_x_0, x_0_sampleArea, givenPhi, max_givenPhi);
	stack<double>* x_0 = inst_initialDistr.get_x_0();
	int length_x_0 = inst_initialDistr.get_length_x_0();
	Generation* generation_0 = new Generation(x_0, 0);

	vector<int> generationToSave = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	vector<int> generationToOpt = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};// 
	
	ExecuterSetting executerSetting(generationToSave, generationToOpt);
	executerSetting.print();

	//
	//	PrimEvolution
	//
	PrimEvolutionSetting primEvolutionSetting(E, m, w, b, EPSILON);
	EvolutionMemory evolutionMemory(generation_0);
	Prim_W prim_W(primEvolutionSetting);
	Prim_P prim_P(primEvolutionSetting);
	GuidedByHO0_W guided_W(primEvolutionSetting);
	GuidedByHO0_P guided_P(primEvolutionSetting);
	EvolutionExecuter <Prim_W, Prim_P> primEvolutionExecuter(evolutionMemory, prim_W, prim_P, executerSetting);
	primEvolutionExecuter.run();
	// EvolutionExecuter <GuidedByHO0_W, GuidedByHO0_P> guidedEvolutionExecuter(evolutionMemory, guided_W, guided_P, executerSetting);
	// guidedEvolutionExecuter.run();

	//	
	//	PrimEvolutionWithEOpt
	//
	// PrimEvolutionSettingWithEOpt* primEvolutionSettingWithEOpt = new PrimEvolutionSetting(numImgTimeSlices, EPSILON, E, givenW, givenP, generationToSave), generationToEOpt;
	// EvolutionMemory* evolutionMemory = new EvolutionMemory(generation_0);
	// PrimEvolutionWithEOpt primEvolutionWithEOpt(evolutionMemory, primEvolutionSettingWithEOpt, gen);
	// primEvolution.run();


	evolutionMemory.print_savedGenerations();

	evolutionMemory.save_allGenerations("../data");

	evolutionMemory.plot_savedGenerations("../code_python/plot_x_0.py", "../data", plotArea[0], plotArea[1], histnum);

}





// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
