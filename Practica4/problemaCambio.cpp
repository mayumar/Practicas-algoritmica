#include "problemaCambio.hpp"
#include "moneda.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void problemaCambio(){
    int cantidad;
    cout << "Introduzca la cantidad de cambio a calcular: ";
    cin >> cantidad;

    vector<Moneda> sistemaMonetario;
    cargarSistemaMonetario(sistemaMonetario, "../sistemamonetario.txt");

    vector<vector<int>> matrizEstados = vector<vector<int>>(sistemaMonetario.size(), vector<int>(cantidad+1));
    cambio(cantidad, sistemaMonetario, matrizEstados);

    vector<int> solucion = vector<int>(sistemaMonetario.size(), 0);
    obtenerSolución(matrizEstados, sistemaMonetario, solucion);

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

    file.close();
}

void cambio(int cantidad, vector<Moneda> &sistemaMonetario, vector<vector<int>> &matrizEstados){
    
    for(int i = 0; i < sistemaMonetario.size(); i++){
        matrizEstados[i][0] = 0;
    }

    for(int i = 0; i < sistemaMonetario.size(); i++){
        for(int j = 1; j <= cantidad; j++){
            if(i == 0){
                matrizEstados[i][j] = 1 + matrizEstados[i][j-sistemaMonetario[0].getValor()];
            }else{
                if(j < sistemaMonetario[i].getValor()){
                    matrizEstados[i][j] = matrizEstados[i-1][j];
                }else{
                    matrizEstados[i][j] = min(matrizEstados[i-1][j], 1+matrizEstados[i][j-sistemaMonetario[i].getValor()]);
                }
            }
        }
    }
}

void obtenerSolución(vector<vector<int>> &matrizEstados, vector<Moneda> &sistemaMonetario, vector<int> &solucion){
    int i = matrizEstados.size()-1;
    int j = matrizEstados[0].size()-1; //N+1-1

    while(j != 0 && i != 0){
        if(matrizEstados[i][j] == matrizEstados[i-1][j]){
            i--;
        }else{
            j -= sistemaMonetario[i].getValor();
            solucion[i]++;
        }
    }

    if(i == 0 && matrizEstados[i][j] != 0){
        solucion[0] = matrizEstados[i][j];
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