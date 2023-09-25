#include "metodos.hpp"
#include "func_seleccion.hpp"
#include "tiempos.hpp"
#include <iostream>
#include <fstream>

void ordenacionSeleccion(){
    //pedir nMin, nMax, inc, rep
    //declarar vectores nElementos, TReales, TEstimados
    /*calcularTiemposOrdSeleccion(nMin, nMax, inc, rep, nElementos, TReales){
        for(i = nMin; i <= nMax; ...){
            declarar vector i elementos
            rellenar vector
            medir tiempo
            ordenar
            medir tiempo
            guardar t en TReales
            guardar n en NElementos
        }
    }
    */

    int nMin, nMax, inc, rep;
    vector<double> tiemposReales, numeroElementos;


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


}

void matrizCuadrado(){

}
void fibonacciRecursivo(){

}

void const exportarDatos(const vector<double> &tiemposReales, const vector<double> &numeroElementos){
    ofstream file("tiemposReales.txt");
    
    for(auto i = 0; i != numeroElementos.size(); i++){
        file << numeroElementos[i] << " " << tiemposReales[i] << endl;
    }

    file.close();
}