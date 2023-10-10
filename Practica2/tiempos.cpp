#include "tiempos.hpp"
#include "quicksort.hpp"
#include "func_aux.hpp"
#include "ClaseTiempo.hpp"
#include "algoritmos_p1.hpp"
#include <iostream>

void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo,
                                             vector<double> &tiemposRealesQS1, vector<double> &tiemposRealesQS2, vector<double> &numeroElementos){

    Clock time;
    int aux;

    cout << "Calculando tiempos para QS1..." << endl << endl;

    for(int i = nMin; i <= nMax; i += incremento){
        vector<int>v(i);
        aux = 0;

        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);
            time.start();
            if(!estaOrdenado(v)){
                quickSort(0, v.size()-1, v);
            }
            if(time.isStarted()){
                time.stop();
            }
            aux += time.elapsed();
        }

        tiemposRealesQS1.push_back(aux/repeticiones);
        numeroElementos.push_back(i);

        cout << "Vector de " << i << " elementos: " << aux/repeticiones << " microsegundos" << endl;

    }

    cout << endl;
    cout << "Calculando tiempos para QS2..." << endl << endl;

    for(int i = nMin; i <= nMax; i += incremento){
        vector<int>v(i);
        aux = 0;

        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);
            time.start();
            if(!estaOrdenado(v)){
                quickSortMejorado(0, v.size()-1, nMediana, nElementosMinimo, v);
            }
            if(time.isStarted()){
                time.stop();
            }
            aux += time.elapsed();
        }

        tiemposRealesQS2.push_back(aux/repeticiones);

        cout << "Vector de " << i << " elementos: " << aux/repeticiones << " microsegundos" << endl;
    }

}