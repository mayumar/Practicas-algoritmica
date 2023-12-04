#ifndef ONESOLUTIONLV_HPP
#define ONESOLUTIONLV_HPP

#include <vector>

using namespace std;

void oneSolLV();
bool nReinasLasVegas(int n, vector<int>& Solucion);
void escribirSolucion(vector<int>& Solucion); //Definido en oneSolutionBT.cpp

bool lugar(int k, vector<int> &solucion); //Definido en allSolutionsBT.cpp

#endif