#include "tiempos.hpp"
#include "func_aux.hpp"
#include "metodos.hpp"
#include "ClaseTiempo.hpp"
#include "sistemaEcuaciones.hpp"
#include <iostream>
#include <cmath>

void tiemposOrdenacionSeleccion(int nMin, int nMax, int repeticiones, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos){
    Clock time;
    int aux;

    for(int i = nMin; i <= nMax; i += incremento){
        vector<int> v(i);
        aux = 0;

        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);
            time.start();
            ordenacionSeleccion(v);
            if(time.isStarted()){
                time.stop();
            }
            aux += time.elapsed();
        }
        tiemposReales.push_back(aux/repeticiones);
        numeroElementos.push_back(i);

        cout << "Vector de " << i << " elementos: " << time.elapsed() << " microsegundos" << endl;

    }

    cout << endl;
}

void tiemposMatrizCuadrado(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &ordenes){
    Clock time;

    for(int i = nMin; i <= nMax; i += incremento){
        vector<vector<double>> m1 = vector<vector<double>>(i, vector<double>(i));
        vector<vector<double>> mres = vector<vector<double>>(i, vector<double>(i));
        rellenarMatrizAleatoria(m1);

        time.start();
        multiplicarMatrices(m1, m1, mres);
        if(time.isStarted()){
            time.stop();
        }
        tiemposReales.push_back(time.elapsed());
        ordenes.push_back(i);
        
        cout << "Matriz de orden " << i << ": " << time.elapsed() << " microsegundos" << endl;
    }

    cout << endl;
}

void tiemposFibonacciRecursivo(int nMin, int nMax, int incremento, vector<double> &tiemposReales, vector<double> &numeroElementos){
    Clock time;

    for(int i = nMin; i <= nMax; i += incremento){
        time.start();
        fibonnaciRecursivo(i);
        if(time.isStarted()){
            time.stop();
        }
        tiemposReales.push_back(time.elapsed());
        numeroElementos.push_back(i);

        cout << "Termino " << i << "-esimo: " << time.elapsed() << " microsegundos" << endl;
    }

    cout << endl;
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

void calcularTiemposEstimadosExponencial(const vector<double> &n, const vector<double> &tiemposReales, const vector<double> &a, vector<double> &tiemposEstimaos){
    
}
