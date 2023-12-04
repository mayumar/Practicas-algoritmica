#include "allSolutionsBT.hpp"

#include <vector>
#include <iostream>

using namespace std;

void allSolBacktracking(){
    int n;
    
    cout << endl << "Introduzca el numero de reinas: ";
    cin >> n;

    vector<vector<int>> Soluciones;
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
                Soluciones.push_back(x);
            }else{
                k++;
                x[k] = -1;
            }
        }else{
            k--;
        }
    }
}

void escribirSoluciones(vector<vector<int>> &Soluciones){
    
    cout << endl << "Soluciones encontradas:" << endl << endl;
    
    for(int i = 0; i < Soluciones.size(); i++){
        cout << "[";
        for(int j = 0; j < Soluciones[0].size()-1; j++){
            cout << Soluciones[i][j] << ",";
        }
        cout << Soluciones[i][Soluciones[0].size()-1] << "] ";
    }
    cout << endl << endl;
}