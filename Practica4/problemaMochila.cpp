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

    vector<vector<double>> matrizEstados = vector<vector<double>>(materiales.size(), vector<double>(v+1));
    mochila(v, materiales, matrizEstados);

    vector<MaterialUsado> solucion;
    for(Material m: materiales){
        solucion.push_back(MaterialUsado(m, 0));
    }
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
    for(int i = 0; i < materiales.size(); i++){
        matrizEstados[i][0] = 0;
    }

    for(int i = 0; i <= volumenMochila; i++){
        if(i < materiales[0].getVolumen()){
            matrizEstados[0][i] = 0;
        }else{
            matrizEstados[0][i] = materiales[0].getPrecio() * materiales[0].getVolumen();
        }
    }

    for(int i = 1; i < materiales.size(); i++){
        for(int j = 1; j <= volumenMochila; j++){
            if(j < materiales[i].getVolumen()){
                matrizEstados[i][j] = matrizEstados[i-1][j];
            }else{
                matrizEstados[i][j] = max(matrizEstados[i-1][j], (materiales[i].getPrecio() * materiales[i].getVolumen())
                                                                + matrizEstados[i-1][j-materiales[i].getVolumen()]);
            }
        }
    }
}

void obtenerSolucion(vector<vector<double>> &matrizEstados, vector<Material> &materiales, vector<MaterialUsado> &solucion){
    int i = matrizEstados.size()-1;
    int j = matrizEstados[0].size()-1; //V+1-1

    while(j != 0 && i >= 0){
        if(matrizEstados[i][j] == matrizEstados[i-1][j]){
            i--;
        }else{
            j -= materiales[i].getVolumen();
            solucion[i].setVolumenUsado(materiales[i].getVolumen());
            i--;
        }
    }
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