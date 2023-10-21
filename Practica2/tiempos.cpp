#include "tiempos.hpp"
#include "quicksort.hpp"
#include "func_aux.hpp"
#include "ClaseTiempo.hpp"
#include "algoritmos_p1.hpp"
#include <iostream>

void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo,
                                             vector<double> &tiemposRealesQS1, vector<double> &tiemposRealesQS2, vector<double> &numeroElementos){

    Clock time;
    int aux1, aux2;

    cout << "Calculando tiempos..." << endl << endl;

    for(int i = nMin; i <= nMax; i += incremento){
        vector<int>v(i);
        vector<int>v2(i);
        aux1 = 0;
        aux2 = 0;

        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);

            for(int i = 0; i < v.size(); i++){
                v2[i] = v[i];
            }

            time.start();
            quickSort(0, v.size()-1, v);
            if(time.isStarted()){
                time.stop();
            }

            if(estaOrdenado(v)){
                aux1 += time.elapsed();
            }
            
            //rellenarVector(v2);
            time.start();
            quickSortMejorado(0, v2.size()-1, nMediana, nElementosMinimo, v2);
            if(time.isStarted()){
                time.stop();
            }
            
            if(estaOrdenado(v)){
                aux2 += time.elapsed();
            }
        }

        tiemposRealesQS1.push_back(aux1/repeticiones);
        tiemposRealesQS2.push_back(aux2/repeticiones);
        numeroElementos.push_back(i);

        cout << "n = " << i << " " << " tQS1 = " << aux1/repeticiones << " tQS2 = " << aux2/repeticiones << " microsegundos" << endl;

    }

}