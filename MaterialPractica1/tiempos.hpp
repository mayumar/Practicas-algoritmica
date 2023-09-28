#ifndef TIEMPOS_HPP
#define TIEMPOS_HPP

#include <vector>

using namespace std;

    void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos);
    void tiemposMatrizCuadrado(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &ordenes);

    void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados);
    double calcularTiempoEstimadoPolinomico(const double &n, vector<double> &a);

#endif