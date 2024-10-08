#ifndef FUNC_AUX_HPP
#define FUNC_AUX_HPP

#include <vector>
using namespace std;

    void rellenarVector(vector<int> &v);
    void rellenarMatrizManual(vector<vector<double>> &m);
    void rellenarMatrizAleatoria(vector<vector<double>> &m);
    void imprimirVector(const vector<double> &v);
    void imprimirMatriz(vector<vector<double>> &m);

    void const exportarDatosReales(const vector<double> &tiemposReales, const vector<double> &numeroElementos);
    void const exportarDatosFinales(const vector<double> &tiemposReales, const vector<double> &numeroElementos, const vector<double> &tiemposEstimados);

#endif