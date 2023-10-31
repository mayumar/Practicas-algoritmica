#ifndef PROBLEMAMOCHILA_HPP
#define PROBLEMAMOCHILA_HPP

#include <vector>
#include "material.hpp"
#include "materialUsado.hpp"
using namespace std;

void problemaMochila();
void cargarMateriales(vector<Material> &materiales, const char *nombrefichero);
void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado> &solucion);
void escribirSolucion(vector<MaterialUsado> &solucion);

#endif