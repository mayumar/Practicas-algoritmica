#include "problemaCambio.hpp"
#include "moneda.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void problemaCambio(){
    int cantidad;
    cout << "Introduzca la cantidad de cambio a calcular: " << endl;
    cin >> cantidad;

    vector<Moneda> sistemaMonetario;
    cargarSistemaMonetario(sistemaMonetario, "../sistemamonetario.txt");

    vector<int> solucion;
    cambio(cantidad, sistemaMonetario, solucion);

    escribirSolucion(solucion, sistemaMonetario);

}

void cargarSistemaMonetario(vector<Moneda> &sistemaMonetario, const char *nombreFrichero){
    ifstream file(nombreFrichero);
    int aux;
    Moneda m;

    if(!file){
        cout << "Error al abrir el fichero" << endl;
        return;
    }

    while(file >> aux){
        sistemaMonetario.push_back(Moneda(aux));
    }
}

void cambio(int cantidad, vector<Moneda> sistemaMonetario, vector<int> &solucion){
    int suma = 0;
    solucion = vector<int>(sistemaMonetario.size(), 0);

    while(suma != cantidad){
        int i = 0;

        while(i < sistemaMonetario.size() && sistemaMonetario[i].getValor() + suma > cantidad){
            i++;
        }

        solucion[i]++;       
        suma += sistemaMonetario[i].getValor();
    }
}

void escribirSolucion(vector<int> &solucion, vector<Moneda> &sistemaMonetario){
    cout << endl << "Solucion:" << endl;

    for(int i = 0;  i < solucion.size(); i++){
        if(solucion[i] != 0){
            cout << solucion[i] << " monedas de " << sistemaMonetario[i].getValor() << " centimos" << endl;
        }
    }

    cout << endl;
}