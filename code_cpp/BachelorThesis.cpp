
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
const int num_x_1 = 400;

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

void runPyScr_plot_x_1(string path, string dataname, float left, float right, int histnum)
{
	string filename = "../code_python/plot_x_1.py";
	string command = "python ";
	string args = " " + path + " " + dataname + " " + to_string(left) + " " + to_string(right) + " "+ to_string(histnum);

	command += filename += args;
	cout << endl << command << endl;
	system(command.c_str());
}


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
		float* x_1;
		int length_x_1;

	public:
		// InitialDistr() 
		// {
		// 	//std::copy(x_1_sampleArea, x_1_sampleArea + 2, pr_x_1_sampleArea);
		// 	//pr_num_x_1 = num_x_1;
		// }

		void print_x_1_sampleArea(void);
		// print_x_1_sampleArea - print the sample Area of x_1

		void generate_x_val(void);
		// generate_x_val - uses Neumann rejection to generate the x_1 distribution according to Phi

		float* get_x_1(void);
		// get_x_1 - getter function for x_1
		// @return float* - addres of x_1 float array (located on heap)

		void save_x_1(string , string);
		// save_x_1 - saves x_1 into a txt-file 
		// @param string - folder location to save to
		// @param sting - dataname to save to

};

class Evolution
{
	private:
		float* x_1;
		int length_x_1;

	public:
		Evolution(float* p_x_1, int p_length_x_1, double)
		{
			x_1 = p_x_1;
			length_x_1 = p_length_x_1;
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
	//printArray(x_1, num_x_1);
	inst_initialDistr.save_x_1("../data/", "x_1");
	runPyScr_plot_x_1("../data/", "x_1", x_1_sampleArea[0], x_1_sampleArea[1], 60);

	//int* hint = new int;
	//*hint = 6;
	//std::cout << "\n" << *hint;
	//system("pause");
}


//
// function definitions 
//

void InitialDistr::print_x_1_sampleArea(void)
{
	std::cout << "\n begin: " << x_1_sampleArea[0] << "\n end: " << x_1_sampleArea[1];
}

void InitialDistr::generate_x_val(void)
{
	x_1 = new float[num_x_1];
	std::uniform_real_distribution<float> d_x_i(x_1_sampleArea[0], x_1_sampleArea[1]);
	std::uniform_real_distribution<float> d_accept(0, maxPhi);
	for (int i = 0; i < num_x_1;) {
		float x_1_i = d_x_i(gen);
		float accept_theshold = d_accept(gen);
		if (Phi(x_1_i) > accept_theshold) {
			x_1[i] = x_1_i;
			++i;
		}
		
	}
	//printArray(x_1, num_x_1);
	length_x_1 = num_x_1;
}

float* InitialDistr::get_x_1(void) {
	return x_1;
}

void InitialDistr::save_x_1(string  folder, string  name) {
	ofstream x_1_savefile;
	x_1_savefile.open(folder + name + ".txt");
	for (int i = 0; i<length_x_1; ++i){
		x_1_savefile << x_1[i] << endl;
	}
	x_1_savefile.close();
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
