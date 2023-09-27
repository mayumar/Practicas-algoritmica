#include "estadisticas.hpp"
#include "func_aux.hpp"
#include "sistemaEcuaciones.hpp"

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

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados){
    return 0;
}