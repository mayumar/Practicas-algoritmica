#include "tiempos.hpp"
#include "func_seleccion.hpp"
#include <iostream>

void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos){

    for(int i = nMin; i <= nMax; i += incremento){
        vector<int> v(i);
        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);
            ordenacionSeleccion(v);
        }
    }


}