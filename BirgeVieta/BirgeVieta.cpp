#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;
using std::setprecision;

double funcion(vector<double> polinomio, int grado, double x, bool division) {
	vector<double> derivada;
	double fx = polinomio[grado];
	for (int i = grado - 1; i >= 0; i--) { //Da los valores a la derivada
		fx *= x;
		fx += polinomio[i];
		derivada.insert(derivada.begin(), fx);
	}
	if (division) { //retorna el valor del polinomio dividido por su derivada evaluada en x
		double fpx = polinomio[grado];
		for (int i = grado - 1; i >= 1; i--) {
			fpx *= x;
			fpx += derivada[i];
		}
		return fx / fpx;
	}
	else { //retorna el valor de un polinomio evaluado en x
		return fx;
	}
}

int main() {
	char sn = 's';
	double err, raiz;
	int grado, maxIteraciones;
	vector<double> polinomio;

	while (sn == 's') {
		system("cls");
		cout << "\tIsaac Emmanuel Santos Ramos 21310435" << endl;
		cout << "Brenda Paola Navarro Alatorre 21310446\n" << endl;
		cout << "\t\t**********************" << endl;
		cout << "\t\t* Metodo Birge Vieta *" << endl;
		cout << "\t\t**********************\n" << endl;

		cout << "\tIngrese el grado del polinomio: ";
		cin >> grado;

		for (int i = grado; i >= 0; i--) {
			double c;
			cout << "\tIngrese el coeficiente del grado " << i << " : ";
			cin >> c;
			polinomio.insert(polinomio.begin(), c);
		}

		cout << "\tIngrese el margen de error: ";
		cin >> err;
		cout << "\tIngrese el numero maximo de iteraciones: ";
		cin >> maxIteraciones;
		cout << endl;

		int raices = 1;
		while (grado > 0) {
			int iter = maxIteraciones;
			//le damos un valor de 0 a la raiz = x
			raiz = 0; /*rand()%100;*/
			//funcion "fabs" devuelve el valor absoluto del argumento
			double primerErr = err;
			while ((err < fabs(funcion(polinomio, grado, raiz, 0))) && (0 < --iter)) {
				raiz -= funcion(polinomio, grado, raiz, 1);
				double E = raiz;
				E -= raiz;
				cout << "\tIteracion: " << primerErr << " | Xi+1 (#" << raices++ << ") is: " << setprecision(5) << raiz << "  -----> E: " << E << endl;
				primerErr += err;
			}
			/*if (0 < iter) {
				double y = polinomio[grado];
				for (int i = grado - 1; i >= 1; i--) {
					y *= raices;
					y += polinomio[i];
					polinomio[i] = y;
				}
				polinomio.erase(polinomio.begin());
				grado--;
			}
			else {*/
				cout << "\n\tYa no hay más raices reales.\n" << endl;
				break;
			//}
		}

		polinomio.clear();

		cout << "\tDesea resolver otro polinomio? s/n: ";
		cin >> sn;
	}
}