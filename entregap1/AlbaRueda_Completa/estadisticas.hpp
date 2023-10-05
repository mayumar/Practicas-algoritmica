#ifndef ESTADISTICAS_HPP
#define ESTADISTICAS_HPP

#include <vector>
using namespace std;

    void ajusteCuadratico(const vector <double> &numeroElementos, const vector <double> &tiemposReales, vector <double> &a);
    void ajusteCubico(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);
    void ajusteExponencial(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);

    double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);

    double sumatorio(const vector <double> &n, const vector <double> &t, int expN, int expT);
    double media(const vector <double> &v);
    double varianza(const vector <double> &v);

#endif