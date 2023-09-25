#include "tiempos.hpp"
#include "func_seleccion.hpp"
#include "ClaseTiempo.cpp"
#include <iostream>

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