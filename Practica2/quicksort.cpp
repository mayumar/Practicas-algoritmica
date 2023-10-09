#include "quicksort.hpp"
#include <iostream>

void quickSort(int iz, int de, std::vector<int> &v){
    int i = iz;
    int j = de;
    int x = v[(iz+de)/2];

    do{
        while(v[i] < x){
            i++;
        }

        while(v[j] > x){
            j--;
        }

        if(i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }

    }while(i < j);

    if(iz < j){
        quickSort(iz, j, v);
    }

    if(i < de){
        quickSort(i, de, v);
    }

}

bool estaOrdenado(const std::vector<int> &v){
    
    for(int i = 0; i < v.size()-1; i++){

        int j = i+1;
        if(v[j] < v[i]){
            return false;
        }

    }

    return true;
}

void rellenarVector(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] = rand()%1000;
    }
}

void imprimirVector(const std::vector<int> &v){
    std::cout << std::endl;

    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }

    std::cout << std::endl;
    
}