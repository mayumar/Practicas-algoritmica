#include "medio_nivel.hpp"
#include "tiempos.hpp"
#include "func_aux.hpp"
#include "algoritmos.hpp"
#include "estadisticas.hpp"

#include <vector>
#include <iostream>

using namespace std;

void ordenacionSeleccion(){

    int nMin, nMax, inc, rep;
    long nEl = -1;
    double t;
    vector<double> tiemposReales, numeroElementos, a(3), tiemposEstimados;


    cout << "Introduzca el numero minimo de elementos: ";
    cin >> nMin;
    cout << endl;

    cout << "Introduzca el numero maximo de elementos: ";
    cin >> nMax;
    cout << endl;

    cout << "Introduzca el incremento del numero de elementos: ";
    cin >> inc;
    cout << endl;

    cout << "Introduzca el numero de repeticiones: ";
    cin >> rep;
    cout << endl;

    tiemposOrdenacionSeleccion(nMin, nMax, rep, inc, tiemposReales, numeroElementos);    
    exportarDatosReales(tiemposReales, numeroElementos);
    ajusteCuadratico(numeroElementos, tiemposReales, a);
    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    double coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    exportarDatosFinales(tiemposReales, numeroElementos, tiemposEstimados);

    cout << "Funcion de curva estimada: ";
    cout << "t(n) = " << a[0] << " + " << a[1] << "*n + " << a[2] << "*n²" << endl;

    cout << "Coeficiente de determinacion: " << coef_det << endl << endl;

    while(nEl != 0){
        cout << "Introduzca numero de elementos para calcular tiempo estimado (0 para salir): ";
        cin >> nEl;
        cout << endl;

        if(nEl != 0){
            t = calcularTiempoEstimadoPolinomico(nEl, a);
            tiempoEstimadoCompleto(t, nEl);
        }
    }
    
}

void matrizCuadrado(){
    int nMin, nMax, inc;
    long orden;
    double t;
    vector<double> tiemposReales, ordenes, a(4), tiemposEstimados;
    /*
    int opt = 0, n;

    cout << "Introduzca el orden de las matrices: ";
    cin >> n;

    vector<vector<double>> m = vector<vector<double>>(n, vector<double>(n));
    
    while(opt < 1 || opt > 2){
        cout << "Elija una opcion para rellenar las matrices(esta eleccion no hace nada): " << endl;
        cout << "1) Manualmente" << endl;
        cout << "2) Aleatoriamente" << endl;
        cout << "> ";
        cin >> opt;

        if(opt < 1 || opt > 2){
            cout << "Error, opcion incorrecta" << endl;
        }
    }
    */

    cout << "Introduzca el orden minimo de las matrices: ";
    cin >> nMin;
    cout << endl;

    cout << "Introduzca el orden maximo de las matrices: ";
    cin >> nMax;
    cout << endl;

    cout << "Introduzca el incremento del orden de las matrices: ";
    cin >> inc;
    cout << endl;

    tiemposMatrizCuadrado(nMin, nMax, inc, tiemposReales, ordenes);
    exportarDatosReales(tiemposReales, ordenes);
    ajusteCubico(ordenes, tiemposReales, a);
    calcularTiemposEstimadosPolinomico(ordenes, a, tiemposEstimados);

    double coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    exportarDatosFinales(tiemposReales, ordenes, tiemposEstimados);

    cout << "Funcion de curva estimada: ";
    cout << "t(n) = " << a[0] << " + " << a[1] << "*n + " << a[2] << "*n² + " << a[3] << "*n³" << endl;

    cout << "Coeficiente de determinacion: " << coef_det << endl << endl;

    while(orden != 0){
        cout << "Introduzca orden de la matriz para calcular tiempo estimado (0 para salir): ";
        cin >> orden;
        cout << endl;

        if(orden != 0){
            t = calcularTiempoEstimadoPolinomico(orden, a);
            tiempoEstimadoCompleto(t, orden);
        }
    }
    
}

void fibonacciRecursivo(){
    int nMin, nMax, inc;
    long nEl;
    double t;
    vector<double> tiemposReales, numeroElementos, tiemposEstimados, a(2);

    cout << "Introduzca el numero minimo de elementos: ";
    cin >> nMin;
    cout << endl;

    cout << "Introduzca el numero maximo de elementos: ";
    cin >> nMax;
    cout << endl;

    cout << "Introduzca el incremento del numero de elementos: ";
    cin >> inc;
    cout << endl;

    tiemposFibonacciRecursivo(nMin, nMax, inc, tiemposReales, numeroElementos);
    exportarDatosReales(tiemposReales, numeroElementos);
    ajusteExponencial(numeroElementos, tiemposReales, a);
    calcularTiemposEstimadosExponencial(numeroElementos, tiemposReales, a, tiemposEstimados);

    double coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    exportarDatosFinales(tiemposReales, numeroElementos, tiemposEstimados);

    cout << "Funcion de curva estimada: ";
    cout << "t(n) = " << a[0] << " + " << a[1] << "*2^n" << endl;

    cout << "Coeficiente de determinacion: " << coef_det << endl << endl;

    while(nEl != 0){
        cout << "Introduzca numero de elementos para calcular tiempo estimado (0 para salir): ";
        cin >> nEl;
        cout << endl;

        if(nEl != 0){
            t = calcularTiempoEstimadoExponencial(nEl, a);
            tiempoEstimadoCompleto(t, nEl);
        }
    }
}