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

    std::cout << "Vector ordenado:";
    imprimirVector(v);

    return 0;
}