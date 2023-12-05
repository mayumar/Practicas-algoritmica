#include "matricesMC.hpp"
#include "ClaseTiempo.hpp"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void matricesMonteCarlo(){
    Clock time;
    int n;

    cout << "Introduzca el orden de las matrices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    rellenarMatriz(A);

    vector<vector<int>> B(n, vector<int>(n));
    rellenarMatriz(B);

    vector<vector<int>> AB(n, vector<int>(n));
    time.start();
    multiplicarMatrices(A, B, AB);
    time.stop();

    cout << endl << "Tiempo de multiplicacion: " << time.elapsed() << " microsegundos" << endl;

    vector<vector<int>> C;
    generarC(AB, C);

    if(C == AB){
        cout << endl << "Son iguales" << endl;
    }else{
        cout << endl << "No son iguales" << endl;
    }

    bool flag = true;
    int k, cont = 1;

    cout << endl << "Indica el numero de pruebas a realizar: ";
    cin >> k;

    time.start();
    for(int i = 0; i < k && flag; i++){
        flag = verificacionMultiplicacionMatrices(A, B, C);
        if(!flag){
            cont++;
        }
    }
    time.stop();

    if(flag){
        cout << endl << "Las matrices son iguales con probabilidad " << (1-pow(0.5,k))*100 << "%" << endl;
    }else{
        cout << endl << "Las matrices no son iguales, " << cont << " intentos" << endl;
    }
    cout << endl << "Tiempo del algoritmo: " << time.elapsed() << " microsegundos" << endl << endl;

}

void imprimirMatriz(vector<vector<int>> &m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void imprimirVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;
}

void rellenarMatriz(vector<vector<int>> &m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            m[i][j] = (rand()%3)-1;
        }
    }
}

void multiplicarMatrices(const vector<vector<int>> &m1, const vector<vector<int>> &m2, vector<vector<int>> &producto){
	for(int i = 0; i < m1.size(); i++){
		for(int j = 0; j < m2[0].size(); j++){
			producto[i][j] = 0;
			for(int k = 0; k < m1[0].size(); k++)
				producto[i][j] = producto [i][j] + m1[i][k]*m2[k][j];
        }
	}
}

void generarC(vector<vector<int>> &AB, vector<vector<int>> &C){
    C = AB;
    if(rand()%2 != 0){
        C[AB.size()/2][AB.size()/2]++;
    }
}

void rellenarVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] = rand()%2;
    }
}

void multiplicarMatrizVector(const vector<vector<int>> &m, const vector<int> &v, vector<int> &producto){
    for(int i = 0; i < v.size(); i++){
        producto[i] = 0;
        for(int j = 0; j < m[0].size(); j++){
            producto[i] += v[j] * m[j][i];
        }
    }
}

bool verificacionMultiplicacionMatrices(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C){
    int n = A.size();
    
    vector<int> X(n);
    rellenarVector(X);

    vector<int> XA(n);
    multiplicarMatrizVector(A, X, XA);

    vector<int> XAB(n);
    multiplicarMatrizVector(B, XA, XAB);

    vector<int> XC(n);
    multiplicarMatrizVector(C, X, XC);

    if(XAB == XC){
        return true;
    }

    return false;
}