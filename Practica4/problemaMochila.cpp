#include "problemaMochila.hpp"
#include "material.hpp"
#include "materialUsado.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void problemaMochila(){
    int v;
    cout << "Introduzca el volumen de la mochila: ";
    cin >> v;

    vector<Material> materiales;
    cargarMateriales(materiales, "../materialesmochila.txt");

    vector<vector<double>> matrizEstados;
    mochila(v, materiales, matrizEstados);

    vector<MaterialUsado> solucion;
    obtenerSolucion(matrizEstados, materiales, solucion);

    escribirSolucion(solucion);
}

void cargarMateriales(vector<Material> &materiales, const char *nombreFichero){
    ifstream file(nombreFichero);
    int etiqueta;
    float volumen, precio;
    
    if(!file){
        cout << "Error al abrir el fichero" << endl;
        return;
    }

    while((file >> etiqueta >> volumen >> precio)){
        materiales.push_back(Material(etiqueta, volumen, precio));
    }
}

void mochila(float volumenMochila, vector<Material> &materiales, vector<vector<double>> &matrizEstados){
    
}

void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<Material> &materiales, vector<MaterialUsado> &solucion){

}

void escribirSolucion(vector<MaterialUsado> &solucion){
    float precioFinal = 0;

    cout << endl << "Solucion: " << endl;
    for(MaterialUsado mu: solucion){
        if(mu.getVolumenUsado() != 0){
            precioFinal += mu.getMaterial().getPrecio() * mu.getVolumenUsado();
            cout << "Material " << mu.getMaterial().getEtiqueta() << ", volumen: " << mu.getVolumenUsado() << endl;
        }
    }

    cout << endl << "Precio total mochila: " << precioFinal << endl << endl;
}