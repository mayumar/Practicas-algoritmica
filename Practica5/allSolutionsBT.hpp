#ifndef ALLSOLUTIONSBT_HPP
#define ALLSOLUTIONSBT_HPP

#include <vector>

using namespace std;

void allSolBacktracking();
void nReinasBacktracking(int n, vector<vector<int>> &Soluciones);
void escribirSoluciones(vector<vector<int>> &Soluciones);

bool lugar(int k, vector<int> &solucion);

#endif