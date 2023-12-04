#ifndef ONESOLUTIONBT_HPP
#define ONESOLUTIONBT_HPP

#include <vector>

using namespace std;

void oneSolBacktracking();
void nReinasBacktracking(int n, vector<int> &Solucion);
void escribirSolucion(vector<int> &Solucion);

bool lugar(int k, vector<int> &solucion); //Definido en allSolutionsBT.cpp

#endif