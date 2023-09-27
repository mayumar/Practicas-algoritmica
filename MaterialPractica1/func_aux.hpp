#ifndef FUNC_AUX_HPP
#define FUNC_AUX_HPP

#include <vector>
using namespace std;

    void rellenarVector(vector<int> &v);
    void imprimirVector(const vector<double> &v);
    void imprimirMatriz(vector<vector<double>> &m);

    double sumatorio(const vector <double> &n, const vector <double> &t, int expN, int expT);
    
    void const exportarDatos(const vector<double> &tiemposReales, const vector<double> &numeroElementos);

#endif