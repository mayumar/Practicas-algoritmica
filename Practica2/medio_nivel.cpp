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
    double aux1 = 0, aux2 = 0;
    
    tiemposOrdenacionVariantesQuicksort(nmin, nMax, incremento, repeticiones, nMediana, nElementosMinimo, tiemposRealesQS1, tiemposRealesQS2, numeroElementos);
    exportarDatosReales(tiemposRealesQS1, tiemposRealesQS2, numeroElementos);

    for(double n: tiemposRealesQS1){
        aux1 += n;
    }

    aux1 /= numeroElementos.size();

    for(double n: tiemposRealesQS2){
        aux2 += n;
    }

    aux2 /= numeroElementos.size();

    cout << "Mejora: " << aux1/aux2 << endl;
    
}