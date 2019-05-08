
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <string>
using namespace std;

std::random_device rd{};
std::mt19937 gen{ rd() };

const double E = 0;
const double m = 1;
const double w = 1;
const double b = 0;

const double imgTime = 20;
const int numImgTimeSlices = 20;
const int x_1_sampleArea[2] = {-10, 10};
const int num_x_1 = 40;

const double PI = 3.141592653589793238463;
//const double H_BAR = 
const double EPSILON = imgTime / numImgTimeSlices;
const double STD = pow(EPSILON / m, 0.5);

//Beginning function
const double maxPhi = pow(m * w / PI, 0.25);
float Phi(double x)
{
	return float(pow(m * w / PI, 0.25)* exp(-0.5 * m * w * pow(x, 2)));
}


void printArray(float* arr, int lenarr)
{
	for (int i = 0; i < lenarr; ++i) {
		std::cout << "\n" << arr[i];
	}
}

//void printArray(float arr[], int lenarr)
//{
//	for (int i = 0; i < lenarr; ++i) {
//		std::cout << "\n" << arr[i];
//	}
//}
//
//
//void printArray(const float arr[], int lenarr)
//{
//	for (int i = 0; i < lenarr; ++i) {
//		std::cout << "\n" << arr[i];
//	}
//}



double potential(double x)
{
	return 0.5* m* pow(w, 2)* pow(x, 2) + b * pow(x, 4);
}

double nextGen(double x_nMinus1)
{
	std::normal_distribution<double> x_n{ x_nMinus1,STD };
	return x_n(gen);
}


double W(double x_nMinus1)
{
	return exp(-EPSILON * (potential(x_nMinus1) - E));
}



class InitialDistr
{
	private:
		float* x_1;;
		int length_x_1;

	public:
		InitialDistr() 
		{
			//std::copy(x_1_sampleArea, x_1_sampleArea + 2, pr_x_1_sampleArea);
			//pr_num_x_1 = num_x_1;
		}

		void print_x_1_sampleArea(void)
		{
			std::cout << "\n begin: " << x_1_sampleArea[0] << "\n end: " << x_1_sampleArea[1];
		}

		void generate_x_val(void)
		{
			x_1 = new float[num_x_1];
			std::uniform_real_distribution<float> d_x_i(x_1_sampleArea[0], x_1_sampleArea[1]);
			std::uniform_real_distribution<float> d_accept(0, maxPhi);
			for (int i = 0; i < num_x_1;) {
				float x_1_i = d_x_i(gen);
				std::cout << "\n" << x_1_i;
				float accept_theshold = d_accept(gen);
				if (Phi(x_1_i) > accept_theshold) {
					x_1[i] = x_1_i;
					std::cout << "\n jay: " << x_1[i];
					++i;
				}
				
			}
			std::cout << "\n array";
			printArray(x_1, num_x_1);
			length_x_1 = num_x_1;
		}

		float* get_x_1(void) {
			return x_1;
		}

		void save_x_1(string  folder, string  name) {
			ofstream x_1_savefile;
			x_1_savefile.open(folder + name + ".txt");
			x_1_savefile << "Writing this to a file.\n";
			x_1_savefile.close();
		}

};



int main()
{
	std::cout.precision(50);
	//const float a[4] = { 0,1,2,3 };
	//float b[4];

	//std::cout << "\n" << a + 4;
	//std::copy(a, a + 4, b);

	//printArray(a, 4);
	//printArray(b, 4);


	InitialDistr inst_initialDistr;
	inst_initialDistr.print_x_1_sampleArea();
	inst_initialDistr.generate_x_val();
	float* x_1 = inst_initialDistr.get_x_1();
	std::cout << "\n preprint";
	printArray(x_1, num_x_1);
	inst_initialDistr.save_x_1("./", "test1");
/*
	double x_1_vals [numx_val];*/
	//{
	//	double x_val_dist = float(x_valArea[1] - x_valArea[0]) / numx_val;
	//	float x_i = x_valArea[0];
	//	for (int i = 0; i < numx_val; x_i += x_val_dist, ++i) {
	//		x_vals[i] = x_i;
	//	}
	//}
	//for (int i = 0; i < numx_val; ++i) {
	//	std::cout << "\n" << x_vals[i];
	//}
	//double Psi[numx_val];

	//for (int i = 0; i < numx_val; ++i) {

	//}

	//std::map<int, int> hist{};
	//for (int n = 0; n < 10000; ++n) {
	//	++hist[std::round(d(gen))];
	//}
	//for (auto p : hist) {
	//	std::cout << std::setw(2)
	//		<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	//}


	/*for (int n = 0; n < 10; ++n) {
		std::cout << "\n" << nextGen(5);
	}*/

	//int* hint = new int;
	//*hint = 6;
	//std::cout << "\n" << *hint;
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
