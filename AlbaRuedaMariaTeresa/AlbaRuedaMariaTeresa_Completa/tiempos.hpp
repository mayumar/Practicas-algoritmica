#ifndef TIEMPOS_HPP
#define TIEMPOS_HPP

#include <vector>

using namespace std;

    void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos);
    void tiemposMatrizCuadrado(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &ordenes);
    void tiemposFibonacciRecursivo(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos);

    void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados);
    double calcularTiempoEstimadoPolinomico(const double &n, vector<double> &a);
    void calcularTiemposEstimadosExponencial(const vector<double> &n, const vector<double> &tiemposReales, const vector<double> &a, vector<double> &tiemposEstimados);
    double calcularTiempoEstimadoExponencial(const double &n, const vector<double> &a);

    void tiempoEstimadoCompleto(double t, long n);

#endif