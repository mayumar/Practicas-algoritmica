#include "quicksort.hpp"
#include <iostream>

int main(){
    std::vector<int> v(10);
    srand(time(0));

    rellenarVector(v);

    std::cout << "Vector sin ordenar:";
    imprimirVector(v);
    std::cout << std::endl;

    quickSort(0, v.size()-1, v);

    if(estaOrdenado(v)){
        std::cout << "Vector ordenado:";
        imprimirVector(v);
    }else{
        std::cout << "No esta ordenado" << std::endl;
    }

    return 0;
}