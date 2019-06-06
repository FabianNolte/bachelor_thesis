
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

#include <PathIntegral/Evolution/EvolutionExecuter.h>
#include <PathIntegral/Evolution/ExecuterSetting.h>
#include <PathIntegral/Evolution/P.h>
#include <PathIntegral/Evolution/W.h>
#include <PathIntegral/Evolution/EvolutionOrganizer.h>

#include <PathIntegral/Data/Memory.h>
#include <PathIntegral/Data/MemoryWrapper.h>
#include <PathIntegral/Data/Setting.h>
#include <PathIntegral/Data/Generation.h>

#include <PathIntegral/StartFunction.h>
#include <PathIntegral/Analyser.h>

using namespace std;






int main()
{
	const double E = 0.5;
	const double m = 1;
	const double w = 1;
	const double b = 2;

	const int 		num_of_memories 	= 20;
	const double 	evolutionStepSize 	= 0.001;
	const int 		evolutionStepNum 	= 3000;
	const double x_0_sampleArea[2] = {-5, 5};
	const int num_x_0 = 5000;

	const double plotArea[2] = {-10, 10};
	const int histnum = 250;

	std::cout.precision(3);

	// Analyser analyser(5);
	// analyser.print();

	StartFunctionHO0 startFunctionHO0(m, w);
	Generation* generation_0 = startFunctionHO0.calc_startingGeneration(x_0_sampleArea, num_x_0);

	vector<int> generationToSave; // = {0, 50, 100, 150, 200, 250, 300};
	vector<int> generationToOpt;// = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200};// 
	for(int i = 0; i <= evolutionStepNum; i+=5){
		generationToSave.insert(generationToSave.end(), i);
	}
	for(int i = 0; i <= evolutionStepNum; i+=5){
		generationToOpt.insert(generationToOpt.end(), i);
	}


	//
	//	PrimEvolution
	//

	vector<double> param {m, w, b};

	Setting setting(E, param, evolutionStepSize, num_of_memories);

	W* w_func = new Prim_W(setting);
	P* p_func = new Prim_P(setting);

	// W* w_func = new GuidedByHO0_W(setting);
	// P* p_func = new GuidedByHO0_P(setting);


	ExecuterSetting executerSetting(generationToSave, generationToOpt, w_func, p_func);
	executerSetting.print();

	MemoryWrapper memoryWrapper;

	EvolutionOrganizer evolutionOrganizer(memoryWrapper, generation_0, setting, executerSetting);
	evolutionOrganizer.run_allEvolutions();

	memoryWrapper.save_allMemories("../images");

	// memory.print_savedGenerations();

	// // memory.save_allGenerations("../data");

	Analyser* analyser = new PrimAnalyser(memoryWrapper, setting, startFunctionHO0);
	analyser->print_data();
	analyser->plot_data("../images");
	analyser->fit_data(5, 0.1);
	// cout << endl << estimatedGroundStateEnergie << endl;


	cout << "end";
	cin.get();
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

