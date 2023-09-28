#include "func_aux.hpp"
#include <iostream>
#include <fstream>

void rellenarVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] = rand()%1000000;
    }
}

void rellenarMatrizManual(vector<vector<double>> &m){
    cout << "Introduzca los distintos elementos de la matriz: " << endl;

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            cout << "Elemento (" << i << "," << j << "): ";
            cin >> m[i][j];
        }
    }
}

void rellenarMatrizAleatoria(vector<vector<double>> &m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            m[i][j] = drand48() * (1.05-0.95)+0.95;
        }
    }
}

void imprimirVector(const vector<double> &v){
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
}

void imprimirMatriz(vector<vector<double>> &m){
    cout << endl;
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void const exportarDatosReales(const vector<double> &tiemposReales, const vector<double> &numeroElementos){
    ofstream file("tiemposReales.txt");
    
    for(auto i = 0; i != numeroElementos.size(); i++){
        file << numeroElementos[i] << " " << tiemposReales[i] << endl;
    }

    file.close();
}

void const exportarDatosFinales(const vector<double> &tiemposReales, const vector<double> &numeroElementos, const vector<double> &tiemposEstimados){
    ofstream file("tiemposFinales.txt");
    
    for(auto i = 0; i != numeroElementos.size(); i++){
        file << numeroElementos[i] << " " << tiemposReales[i] << " " << tiemposEstimados[i] << endl;
    }

    file.close();
}

double sumatorio(const vector <double> &n, const vector <double> &t, int expN, int expT){
    double multn, multt, sum = 0;

    for(int i = 0; i < n.size(); i++){
        multn = 1;
        multt = 1;

        for(int j = 0; j < expN; j++){
            multn *= n[i];
        }

        for(int j = 0; j < expT; j++){
            multt *= t[i];
        }

        sum += (multn*multt);
    }

    return sum;
}