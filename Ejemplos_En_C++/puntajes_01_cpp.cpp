#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

struct Puntajes {
	string nombre;
	int puntaje;
	double tiempo;
};
Puntajes puntajes[2];

void guardar_puntajes(string nombre_archivo){
	ofstream archivo;
	archivo.open(nombre_archivo, ios::app);
	for (int i = 1; i <= 2; i++){
		archivo << puntajes[i].nombre << " " << puntajes[i].puntaje << " " << puntajes[i].tiempo << endl;
	}
	archivo.close();
}

void recuperar_puntajes(string nombre_archivo){
	ifstream archivo;
	archivo.open(nombre_archivo, ios::in);
	for (int i = 0; i <= 2; i++){
		archivo >> puntajes[i].puntaje;
		cout << puntajes[i].puntaje << endl;
	}
	archivo.close();


}


int main(){
	puntajes[1].nombre = "Raul";
	puntajes[1].puntaje = 8;
	puntajes[1].tiempo = 12.32;
	puntajes[2].nombre = "Sandra";
	puntajes[2].puntaje = 54;
	puntajes[2].tiempo = 8.21;
	guardar_puntajes("Puntajes.txt");
	recuperar_puntajes("Puntajes.txt");
	Sleep(5000);

	return 0;
}
