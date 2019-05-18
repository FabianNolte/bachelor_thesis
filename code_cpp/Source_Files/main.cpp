
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

#include "../Header_Files/Evolution/EvolutionExecuter.h"
#include "../Header_Files/Evolution/ExecuterSetting.h"
#include "../Header_Files/Evolution/P.h"
#include "../Header_Files/Evolution/W.h"

#include "../Header_Files/Data/Memory.h"
#include "../Header_Files/Data/Setting.h"
#include "../Header_Files/Data/Generation.h"

#include "../Header_Files/StartFunction.h"
//#include "../Header_Files/Analyser.h"

using namespace std;






int main()
{
	const double E = 2;
	const double m = 1;
	const double w = 4;
	const double b = 0;

	const double evolutionStepSize = 0.001;
	const double x_0_sampleArea[2] = {-10, 10};
	const int num_x_0 = 5000;

	const double plotArea[2] = {-10, 10};
	const int histnum = 250;

	std::cout.precision(3);

	// Analyser analyser(5);
	// analyser.print();

	StartFunctionHO0 startFunctionHO0(m, w);
	Generation* generation_0 = startFunctionHO0.calc_startingGeneration(x_0_sampleArea, num_x_0);

	vector<int> generationToSave = {0, 50, 100, 150, 200, 250, 300};
	vector<int> generationToOpt;// = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200};// 
	for(int i = 0; i <= 300; i+=5){
		generationToOpt.insert(generationToOpt.end(), i);
	}

	ExecuterSetting executerSetting(generationToSave, generationToOpt);
	executerSetting.print();

	//
	//	PrimEvolution
	//

	vector<double> param {m, w, b};

	Setting setting(E, param, evolutionStepSize);
	Memory memory(generation_0);

	W* w_func = new Prim_W(setting);
	P* p_func = new Prim_P(setting);

	// W* w_func = new GuidedByHO0_W(setting);
	// P* p_func = new GuidedByHO0_P(setting);

	EvolutionExecuter evolutionExecuter(memory, w_func, p_func, executerSetting);
	evolutionExecuter.run();

	double estimatedGroundStateEnergie = memory.get_guessedGroundstateEnergy();

	memory.print_savedGenerations();

	// memory.save_allGenerations("../data");

	cout << endl << estimatedGroundStateEnergie << endl;
	memory.plot_savedGenerations(plotArea[0], plotArea[1], histnum);


	cout << endl << estimatedGroundStateEnergie << endl;

	system("pause");
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
