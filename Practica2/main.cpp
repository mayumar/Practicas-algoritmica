#include "quicksort.hpp"
#include <iostream>

int main(){
    std::vector<int> v(100000);
    std::vector<int> u(100000);
    srand(time(0));

    rellenarVector(v);
    rellenarVector(u);

    std::cout << "Vectores sin ordenar:";
    imprimirVector(v);
    imprimirVector(u);
    std::cout << std::endl;

    quickSort(0, v.size()-1, v);

    if(estaOrdenado(v)){
        std::cout << "Vector ordenado con quicksort:";
        imprimirVector(v);
    }else{
        std::cout << "No esta ordenado" << std::endl;
    }

    return 0;
}