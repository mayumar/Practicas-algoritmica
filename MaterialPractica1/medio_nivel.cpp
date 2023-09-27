#include "medio_nivel.hpp"
#include "tiempos.hpp"
#include "func_aux.hpp"
#include "metodos.hpp"
#include "estadisticas.hpp"

#include <vector>
#include <iostream>

using namespace std;

void ordenacionSeleccion(){

    int nMin, nMax, inc, rep;
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
    exportarDatos(tiemposReales, numeroElementos);
    ajusteCuadratico(numeroElementos, tiemposReales, a);
    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    double coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);


}

void matrizCuadrado(){

}
void fibonacciRecursivo(){

}