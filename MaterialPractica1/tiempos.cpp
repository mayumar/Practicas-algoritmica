#include "tiempos.hpp"
#include "func_aux.hpp"
#include "metodos.hpp"
#include "ClaseTiempo.hpp"
#include <iostream>
#include <cmath>

void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos){
    Clock time;
    int it = 0;

    for(int i = nMin; i <= nMax; i += incremento){
        vector<int> v(i);

        numeroElementos.push_back(i);
        tiemposReales.push_back(0);

        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);
            time.start();
            ordenacionSeleccion(v);
            time.stop();
            tiemposReales[it] += time.elapsed();
        }
        tiemposReales[it] /= repeticiones;
        it++;
    }
}

void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados){
    for(int i = 0; i < numeroElementos.size(); i++){
        double aux = 0;
        for(int j = 0; j < a.size(); j++){
            aux += a[j]*pow(numeroElementos[i], j);
        }
        tiemposEstimados.push_back(aux);
    }
}