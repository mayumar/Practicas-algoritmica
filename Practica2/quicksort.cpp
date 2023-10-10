#include "quicksort.hpp"
#include "algoritmos_p1.hpp"
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

void quickSortMejorado(int iz, int de, int med, int n, std::vector<int> &v){
    int i = iz;
    int j = de;
    int x;
    
    if(v.size() < med){
        x = v[(iz+de)/2];
    }else{
        std::vector<int> m;

        for(int i = 0; i < n-1; i++){
            m.push_back(v[i]);
        }

        ordenacionSeleccion(m);

        x = m[(n-1)/2];
    }

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