#include "func_aux.hpp"
#include <iostream>
#include <fstream>

void rellenarVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] = rand()%1000000;
    }
}

void imprimirVector(const vector<int> &v){
    cout << endl;

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;
    
}

void const exportarDatosReales(const vector<double> &tiemposRealesQS1, const vector<double> &tiemposRealesQS2, const vector<double> &numeroElementos){
    ofstream file("tiemposReales.txt");
    
    for(auto i = 0; i != numeroElementos.size(); i++){
        file << numeroElementos[i] << " " << tiemposRealesQS1[i] << " " << tiemposRealesQS2[i] << endl;
    }

    file.close();
}