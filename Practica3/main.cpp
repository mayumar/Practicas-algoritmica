#include <iostream>

using namespace std;

void problemaCambio();

int main(){
    int opt;

    do{
        cout << "Seleccione una opcion:" << endl;
        cout << "1) Problema del cambio" << endl;
        cout << "2) Problema de la mochila" << endl;
        cout << "3) Salir" << endl;
        cout << "> ";
        cin >> opt;

        switch(opt){
            case 1:
                problemaCambio();
            break;

            case 2:
                void problemaMochila();
            break;

            case 3:
                cout << "Saliendo..." << endl;
            break;

            default:
                cout << "Introduzca una opcion correcta" << endl;
        }

    }while(opt != 3);



    return 0;
}