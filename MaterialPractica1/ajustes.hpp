#ifndef AJUSTES_HPP
#define AJUSTES_HPP
#include <vector>
using namespace std;

    void ajusteCuadratico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a);
    double sumatorio(const vector <double> &n, const vector <double> &t, int expN, int expT);

    void imprimirMatriz(vector<vector<double>> &m);

    double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);

#endif