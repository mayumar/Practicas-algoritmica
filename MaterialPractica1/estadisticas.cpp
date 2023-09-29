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

void ajusteCubico(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a){
    ajusteCuadratico(n, tiemposReales, a);
}

double media(const vector <double> &v){
    double sum = 0;

    for(int i = 0; i < v.size(); i++){
        sum += v[i];
    }

    return (sum/v.size());
}

double varianza(const vector <double> &v){
    double sum = 0;
    double med = media(v);
    
    for(int i = 0; i < v.size(); i++){
        sum += ((v[i] - med) * (v[i] - med));
    }

    return (sum/(v.size()-1));
}

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados){
    
    double var_reales = varianza(tiemposReales);
    double var_estimados = varianza(tiemposEstimados);

    return (var_estimados/var_reales);
}