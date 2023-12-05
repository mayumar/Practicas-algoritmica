#include <iostream>

using namespace std;

void allSolBacktracking();
void oneSolBacktracking();
void oneSolLV();
void matricesMonteCarlo();

int main(){
    int opt;
    srand(time(0));

    do{
        cout << "Elija una opcion para resolver n reinas:" << endl;
        cout << "[1] Todas las soluciones con Backtracking" << endl;
        cout << "[2] Una solucion con Backtracking" << endl;
        cout << "[3] Una solucion con el algoritmo de las Vegas" << endl;
        cout << "[4] Producto de matrices con el algoritmo de Monte Carlo" << endl;
        cout << "[5] Salir" << endl;
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
                matricesMonteCarlo();
            break;

            case 5:
                cout << endl << "Saliendo..." << endl;
            break;

            default:
                cout << endl << "Introduzca una opcion correcta" << endl << endl;
        }

    }while(opt != 5);

    return 0;
}