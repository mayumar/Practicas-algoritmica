#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

    void quickSort(int iz, int de, std::vector<int> &v);
    void quickSortMejorado(int iz, int de, std::vector<int> &v, int n);
    bool estaOrdenado(const std::vector<int> &v);
    void rellenarVector(std::vector<int> &v);
    void imprimirVector(const std::vector<int> &v);

    void ordenacionSeleccion(std::vector<int>&v);

#endif