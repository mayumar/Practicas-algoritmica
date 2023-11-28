#include "allSolutionsBT.hpp"

#include <vector>
#include <iostream>

using namespace std;

void allSolBacktracking(){
    int n;
    
    cout << endl << "Introduzca el numero de reinas: ";
    cin >> n;

    vector<vector<int>> Soluciones(n, vector<int>(n));
    nReinasBacktracking(n, Soluciones);
    escribirSoluciones(Soluciones);
}

bool lugar(int k, vector<int> &solucion){
    for(int i = 0; i < k; i++){
        if(solucion[i] == solucion[k] || abs(solucion[i] - solucion[k]) == abs(i - k)){
            return false;
        }
    }

    return true;
}

void nReinasBacktracking(int n, vector<vector<int>> &Soluciones){
    Soluciones[0][0] = -1;
    int k = 0;
    int i = 0;
    while(k > -1){
        Soluciones[i][k] = Soluciones[i][k]+1;
        while(Soluciones[i][k] < n && !lugar(k, Soluciones[i])){
            Soluciones[i][k] = Soluciones[i][k] + 1;
        }
        if(Soluciones[i][k] < n){
            if(k != n-1){
                k++;
                Soluciones[i][k] = -1;
            }
        }else{
            k--;
            i++;
            Soluciones[i][k] = -1;
        }
    }
}

void escribirSoluciones(vector<vector<int>> &Soluciones){
    for(int i = 0; i < Soluciones.size(); i++){
        cout << "[ ";
        for(int j = 0; j < Soluciones[0].size(); j++){
            cout << Soluciones[i][j] << " ";
        }
        cout << "]" << endl;
    }
}