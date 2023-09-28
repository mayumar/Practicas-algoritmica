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
            cout << "Vector de " << i << " elementos, repeticion numero " << j+1 << ": " << time.elapsed() << " microsegundos" << endl;
        }

        cout << endl;
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

double calcularTiempoEstimadoPolinomico(const double &n, vector<double> &a){
    double res = 0;

    for(int i = 0; i < a.size(); i++){
        res += a[i]*pow(n, i);
    }
        
    return res;
}
