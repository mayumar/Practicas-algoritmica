#ifndef PROBLEMACAMBIO_HPP
#define PROBELMACAMBIO_HPP

#include <vector>
#include "moneda.hpp"
using namespace std;

void problemaCambio();

void cargarSistemaMonetario(vector<Moneda> &sistemaMonetario, const char *nombreFrichero);
void cambio(int cantidad, vector<Moneda> &sistemaMonetario, vector<vector<int>> &matrizEstados);
void obtenerSolución(vector<vector<int>> &matrizEstados, vector<Moneda> &sistemaMonetario, vector<int> &solucion);
void escribirSolucion(vector<int> &solucion, vector<Moneda> &sistemaMonetario);

#endif