#include "medio_nivel.hpp"
#include "tiempos.hpp"
#include "func_aux.hpp"
#include <iostream>
#include <vector>

using namespace std;

void comparacionVariantesQuicksort(int nmin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo){
    vector<double> tiemposRealesQS1;
    vector<double> tiemposRealesQS2;
    vector<double> numeroElementos;
    
    tiemposOrdenacionVariantesQuicksort(nmin, nMax, incremento, repeticiones, nMediana, nElementosMinimo, tiemposRealesQS1, tiemposRealesQS2, numeroElementos);
    exportarDatosReales(tiemposRealesQS1, tiemposRealesQS2, numeroElementos);
    
}