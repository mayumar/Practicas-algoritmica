#include "tiempos.hpp"
#include "func_aux.hpp"
#include "algoritmos.hpp"
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
            if(!estaOrdenado(v)){
                ordenacionSeleccion(v);
            }
            if(time.isStarted()){
                time.stop();
            }
            aux += time.elapsed();
        }
        tiemposReales.push_back(aux/repeticiones);
        numeroElementos.push_back(i);

        cout << "Vector de " << i << " elementos: " << aux << " microsegundos" << endl;

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

void calcularTiemposEstimadosExponencial(const vector<double> &n, const vector<double> &tiemposReales, const vector<double> &a, vector<double> &tiemposEstimados){
    for(int i = 0; i < n.size(); i++){
        double aux = a[0] + (a[1] * pow(2, n[i]));
        tiemposEstimados.push_back(aux);
    }
}

double calcularTiempoEstimadoExponencial(const double &n, const vector<double> &a){
    return (a[0] + (a[1] * pow(2, n)));
}

void tiempoEstimadoCompleto(double t, long n){
    long seg = t/1000000;
    long min = seg/60;
    long hours = min/60;
    long days = hours/24;
    long years = days/365;

    seg = seg%60;
    min = min%60;
    hours = hours%24;
    days = days%365;

    cout << "Para n = " << n << ", tardara " << years << " años, " << days << " dias, "
            << hours << " horas, " << min << " minutos, " << seg << " segundos" << endl << endl;
}

