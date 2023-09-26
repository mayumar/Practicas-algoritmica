#include "ajustes.hpp"
#include "sistemaEcuaciones.hpp"
#include <iostream>

void ajusteCuadratico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a){
    int grado = a.size();
    
    vector <vector <double>> matrizDatos;
    matrizDatos = vector <vector <double>>(grado, vector <double>(grado));

    for(int i = 0; i < grado; i++){
        for(int j = 0; j < grado; j++){
            matrizDatos[i][j] = sumatorio(numeroElementos, tiemposReales, i+j, 0);
        }
    }

    vector <vector <double>> matrizInd;
    matrizInd = vector <vector <double>>(grado, vector <double>(1));

    for(int i = 0; i < grado; i++){
        matrizInd[i][0] = sumatorio(numeroElementos, tiemposReales, i, 1);
    }

    vector <vector <double>> X;
    X = vector <vector <double>>(grado, vector <double>(1));

    resolverSistemaEcuaciones(matrizDatos, matrizInd, grado, X);

    for(int i = 0; i < grado; i++){
        a[i] = X[i][0];
    }
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

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados){
    return 0;
}