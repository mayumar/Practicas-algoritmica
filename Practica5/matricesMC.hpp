#ifndef MATRICESMC_HPP
#define MATRICESMC_HPP

#include <vector>

using namespace std;

void matricesMonteCarlo();

void imprimirMatriz(vector<vector<int>> &m);
void imprimirVector(vector<int> &v);
void rellenarMatriz(vector<vector<int>> &m);
void multiplicarMatrices(const vector <vector<int>> &m1, const vector<vector<int>> &m2, vector<vector<int>> &producto);
void generarC(vector<vector<int>> &AB, vector<vector<int>> &C);
void rellenarVector(vector<int> &v);
void multiplicarMatrizVector(const vector<vector<int>> &m, const vector<int> &v, vector<int> &producto);

bool verificacionMultiplicacionMatrices(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C);


#endif