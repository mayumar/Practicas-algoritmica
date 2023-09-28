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

    cout << "Coeficiente de determinacion: " << coef_det << endl << endl;

    while(nEl != 0){
        cout << "Introduzca numero de elementos para calcular tiempo estimado (0 para salir): ";
        cin >> nEl;
        cout << endl;

        t = calcularTiempoEstimadoPolinomico(nEl, a);

        float seg = t/1000000;
        int min = seg/60;
        int hours = min/60;
        int days = hours/24;
        int years = days/365;

        cout << "Para " << nEl << " elementos, tardara " << years << " años, " << days << " dias, "
             << hours << " horas, " << min << " minutos, " << seg << " segundos" << endl << endl;
    }
    
}

void matrizCuadrado(){
    int nMin, nMax, inc;
    vector<double> tiemposReales, ordenes;
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
    
}
void fibonacciRecursivo(){

}