
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

std::random_device rd{};
std::mt19937 gen{ rd() };

const double E = 0.5;
const double m = 1;
const double w = 1;
const double b = 0;

const double imgTime = 20;
const int numImgTimeSlices = 50;
const int x_1_sampleArea[2] = {-10, 10};
const int num_x_1 = 400;

const double PI = 3.141592653589793238463;
//const double H_BAR = 
const double EPSILON = imgTime / numImgTimeSlices;
const double STD = pow(EPSILON / m, 0.5);

//Beginning function
const double maxPhi = pow(m * w / PI, 0.25);
double Phi(double x)
{
	return pow(m * w / PI, 0.25)* exp(-0.5 * m * w * pow(x, 2));
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

double nextGen(double x_nMinus1)
{
	std::normal_distribution<double> x_n{ x_nMinus1,STD };
	return x_n(gen);
}






class InitialDistr
{
	private:
		double* x_1;
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

		double* get_x_1(void);
		// get_x_1 - getter function for x_1
		// @return double* - addres of x_1 double array (located on heap)

		int get_length_x_1(void);
		// get_length_x_1 - getter function for length_x_1
		// @return int - number of elements in x_1

		void save_x_1(string , string);
		// save_x_1 - saves x_1 into a txt-file 
		// @param string - folder location to save to
		// @param string - dataname to save to

};

class Evolution
{
	private:
		double* x_1;
		int length_x_1;
		double* x_N;
		int length_x_N;

		int evolution_stepNum;
		double evolution_step;

		double E;
		
		int replicationNum = 0;

		double (*W_x_n)(double, double, double);
		stack<double>* (*P_x_n_to_x_nPlus1)(double, double, int);

	public:
		Evolution(double* p_x_1, int p_length_x_1)
		{
			x_1 = p_x_1;
			length_x_1 = p_length_x_1;
		}

		void evolution_caller(int p_evolution_stepNum, double p_evolution_step, double p_E, double (*p_W_x_n)(double, double, double), stack<double>* (*p_P_x_n_to_x_nPlus1)(double, double, int))
		{
			evolution_stepNum = p_evolution_stepNum;
			evolution_step = p_evolution_step;
			W_x_n = p_W_x_n;
			P_x_n_to_x_nPlus1 = p_P_x_n_to_x_nPlus1;
			E = p_E;
			stack<double> stack_x_N;
			for(int i = 0; i < length_x_1; ++i) {
				evolution_executer(x_1[i], 1, stack_x_N);
				cout << "finished with x_1_i = " << i << endl;
			}
			length_x_N = stack_x_N.size();
			x_N = new double[length_x_N];
			for(int i = 0; i < length_x_N; ++i) {
				x_N[i] = stack_x_N.top();
				stack_x_N.pop();
			}
		}

		void evolution_executer(double x_n, int n, stack<double>& stack_x_N)
		{
			if(n == evolution_stepNum){
				//add to result stack
				stack_x_N.push(x_n);
			}

			else{
				//calc multipicity accorting to W
				int replicationNumFor_x_n = calc_replicationNumFor_x_n(x_n);
				replicationNum += replicationNumFor_x_n;
				//calc x_nPlus1 according to P with multipicity according to W
				
				//TODO =0 question
				stack<double>* x_nPlus1 = P_x_n_to_x_nPlus1(x_n, evolution_step, replicationNumFor_x_n);
				//call evolution_executer for all x_nPlus1
				for(int i=0; i < replicationNumFor_x_n; ++i){
					evolution_executer((*x_nPlus1).top(), n+1, stack_x_N);
					(*x_nPlus1).pop();
				}
			}
		}

		int calc_replicationNumFor_x_n(double x_n)
		{
			int replicationNumFor_x_n;
			double W = W_x_n(x_n, E, evolution_step);
			replicationNumFor_x_n = int(W);
			std::uniform_real_distribution<double> d_accept(0, 1);
			if(d_accept(gen) <= W-replicationNumFor_x_n){
				++replicationNumFor_x_n;
			}
			return replicationNumFor_x_n;
		}

		double* get_x_N(void);
		// get_x_N - getter function for x_N
		// @return double* - addres of x_N double array (located on heap)

		int get_length_x_N(void);
		// get_length_x_N - getter function for length_x_N
		// @return int - number of elements in x_N

		void save_x_N(string , string);
		// save_x_N - saves x_N into a txt-file 
		// @param string - folder location to save to
		// @param string - dataname to save to
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
	double* x_1 = inst_initialDistr.get_x_1();
	int length_x_1 = inst_initialDistr.get_length_x_1();
	//printArray(x_1, num_x_1);
	inst_initialDistr.save_x_1("../data/", "x_1");
	//runPyScr_plot_x_1("../data/", "x_1", x_1_sampleArea[0], x_1_sampleArea[1], 60);

	Evolution inst_evolution(x_1, length_x_1);
	inst_evolution.evolution_caller(numImgTimeSlices, EPSILON, E, givenW, givenP);
	cout << "vor save_x_N" << endl;
	inst_evolution.save_x_N("../data/", "x_N");
	runPyScr_plot_x_1("../data/", "x_N", x_1_sampleArea[0], x_1_sampleArea[1], 60);

	//int* hint = new int;
	//*hint = 6;
	//std::cout << "\n" << *hint;
	//system("pause");

	delete[] x_1;
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
	x_1 = new double[num_x_1];
	std::uniform_real_distribution<double> d_x_i(x_1_sampleArea[0], x_1_sampleArea[1]);
	std::uniform_real_distribution<double> d_accept(0, maxPhi);
	for (int i = 0; i < num_x_1;) {
		double x_1_i = d_x_i(gen);
		double accept_theshold = d_accept(gen);
		if (Phi(x_1_i) >= accept_theshold) {
			x_1[i] = x_1_i;
			++i;
		}
		
	}
	//printArray(x_1, num_x_1);
	length_x_1 = num_x_1;
}

double* InitialDistr::get_x_1(void) {
	return x_1;
}

int InitialDistr::get_length_x_1(void) {
	return length_x_1;
}

void InitialDistr::save_x_1(string  folder, string  name) {
	ofstream x_1_savefile;
	x_1_savefile.open(folder + name + ".txt");
	for (int i = 0; i<length_x_1; ++i){
		x_1_savefile << x_1[i] << endl;
	}
	x_1_savefile.close();
}



double* Evolution::get_x_N(void) {
	return x_N;
}

int Evolution::get_length_x_N(void) {
	return length_x_N;
}

void Evolution::save_x_N(string  folder, string  name) {
	ofstream x_N_savefile;
	x_N_savefile.open(folder + name + ".txt");
	for (int i = 0; i<length_x_N; ++i){
		x_N_savefile << x_N[i] << endl;
	}
	cout << folder + name + ".txt" << endl;
	x_N_savefile.close();
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
