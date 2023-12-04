#include "oneSolutionLV.hpp"
#include <vector>
#include <iostream>

using namespace std;

void oneSolLV(){
    int n, cont = 1;

    cout << endl << "Introduzca el numero de reinas: ";
    cin >> n;

    vector<int> Solucion;
    bool exito = false;

    while(!exito){
        exito = nReinasLasVegas(n, Solucion);

        if(exito){
            cout << endl << "Se ha encontrado solucion con " << cont << " intentos" << endl;
            escribirSolucion(Solucion);
        }else{
            cont++;
        }
    }
    
}

bool nReinasLasVegas(int n, vector<int>& Solucion){
    bool exito = true;
    Solucion = vector<int>(n, 0);
    vector<int> ok(n);
    int cont;

    for(int k = 0; k < n && exito; k++){
        cont = -1;
        for(int j = 0; j < n; j++){
            Solucion[k] = j;
            if(lugar(k, Solucion)){
                cont++;
                ok[cont] = j;
            }
        }
        if(cont == -1){
            exito = false;
        }else{
            int columna = ok[rand()%(cont+1)];
            Solucion[k] = columna;
        }
    }

    return exito;
}