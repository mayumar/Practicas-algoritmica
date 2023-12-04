#include <iostream>

using namespace std;

void allSolBacktracking();
void oneSolBacktracking();
void oneSolLV();

int main(){
    int opt;
    srand(time(0));

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
                oneSolBacktracking();
            break;

            case 3:
                oneSolLV();
            break;

            case 4:
                cout << endl << "Saliendo..." << endl;
            break;

            default:
                cout << endl << "Introduzca una opcion correcta" << endl;
        }

    }while(opt != 4);

    return 0;
}