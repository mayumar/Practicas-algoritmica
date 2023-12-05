#include "oneSolutionBT.hpp"
#include "ClaseTiempo.hpp"
#include <vector>
#include <iostream>

using namespace std;

void oneSolBacktracking(){
    int n;

    cout << endl << "Introduzca el numero de reinas: ";
    cin >> n;

    vector<int> Solucion;
    Clock time;

    time.start();
    nReinasBacktracking(n, Solucion);
    time.stop();

    escribirSolucion(Solucion);
    cout << "Tiempo: " << time.elapsed() << " microsegundos" << endl << endl;
}

void nReinasBacktracking(int n, vector<int> &Solucion){
    vector<int> x(n);

    x[0] = -1;
    int k = 0;

    while(k > -1){
        x[k]++;

        while(x[k] < n && !lugar(k, x)){
            x[k]++;
        }

        if(x[k] < n){
            if(k == n-1){
                Solucion = vector<int>(x);
            }else{
                k++;
                x[k] = -1;
            }
        }else{
            k--;
        }
    }
}

void escribirSolucion(vector<int> &Solucion){
    
    cout << endl << "Solucion: ";
    
    cout << "[";

    for(int i = 0; i < Solucion.size()-1; i++){
        cout << Solucion[i] << ",";
    }

    cout << Solucion[Solucion.size()-1] << "]" << endl << endl;
}