#include <iostream>
#include "medio_nivel.hpp"

using namespace std;

int main(){
    int opt = -1;
    srand(time(0));

    while(opt != 4){
        cout << "Elija una opcion:" << endl;
        cout << "1) Ordenacion por seleccion" << endl;
        cout << "2) Cuadrado de una matriz" << endl;
        cout << "3) Sucesion de Fibonacci" << endl;
        cout << "4) Salir" << endl;
        cout << "> ";
        cin >> opt;

        if(opt < 1 || opt > 4){
            cout << "Error, elija una opcion correcta" << endl;
        }

        cout << endl;

        switch(opt){
            case 1:
                ordenacionSeleccion();
            break;

            case 2:
                matrizCuadrado();
            break;

            case 3:
                fibonacciRecursivo();
            break;

            default:

            break;
        }
    }

    return 0;
}