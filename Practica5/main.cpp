#include <iostream>

using namespace std;

void allSolBacktracking();
void oneSolBacktracking();
void oneSolLV();

int main(){
    int opt;

    do{
        cout << "Elija una opcion para la resolucion del problema:" << endl;
        cout << "1) Todas las soluciones con Backtracking" << endl;
        cout << "2) Una solucion con Backtracking" << endl;
        cout << "3) Una solucion con el algoritmo de las Vegas" << endl;
        cout << "4) Salir" << endl;
        cout << "> ";
        cin >> opt;

        switch(opt){
            case 1:
                allSolBacktracking();
            break;

            case 2:
                cout << "Una solucion con backtracking" << endl;
            break;

            case 3:
                cout << "Una solucion con el algoritmo de las Vegas" << endl;
            break;

            case 4:
                cout << "Saliendo..." << endl;
            break;

            default:
                cout << "Introduzca una opcion correcta" << endl;
        }

    }while(opt != 4);

    return 0;
}