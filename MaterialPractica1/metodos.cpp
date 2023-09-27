#include "metodos.hpp"

void ordenacionSeleccion(vector<int>&v){
    for(int i = 0; i < v.size()-1; i++){
        int min_pos = i;
        for(int j = i+1; j < v.size(); j++){
            if(v[j] < v[min_pos]){
                min_pos = j;
            }
        }

        int aux = v[i];
        v[i] = v[min_pos];
        v[min_pos] = aux;
    }
}

bool estaOrdenado(const vector<int> &v){
    
    for(int i = 0; i < v.size()-1; i++){

        int j = i+1;
        if(v[j] < v[i]){
            return false;
        }

    }

    return true;
}