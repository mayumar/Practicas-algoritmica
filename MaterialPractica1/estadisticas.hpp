#ifndef ESTADISTICAS_HPP
#define ESTADISTICAS_HPP

#include <vector>
using namespace std;

    void ajusteCuadratico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a);

    double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);

#endif