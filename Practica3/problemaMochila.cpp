#include "problemaMochila.hpp"
#include "material.hpp"
#include "materialUsado.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void problemaMochila(){
    int v;
    cout << "Introduzca el volumen de la mochila: " << endl;
    cin >> v;

    vector<Material> materiales;
    cargarMateriales(materiales, "../materialesmochila.txt");

    vector<MaterialUsado> solucion;
    mochila(v, materiales, solucion);

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

void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado> &solucion){
    float resto = volumenMochila;
    bool materialDisponible;

    for(size_t i = 0; i < materiales.size(); i++){
        solucion.push_back(MaterialUsado(materiales[i], 0));
    }

    do{
        float precioMaximo = 0;
        int materialMaximo;
        materialDisponible = false;
        for(int i = 0; i < materiales.size(); i++){
            if(solucion[i].getVolumenUsado() == 0){
                materialDisponible = true;
                if(materiales[i].getPrecio() > precioMaximo){
                    precioMaximo = materiales[i].getPrecio();
                    materialMaximo = i;
                }
            }
        }

        if(materialDisponible){
            if(resto >= materiales[materialMaximo].getVolumen()){
                solucion[materialMaximo].setVolumenUsado(materiales[materialMaximo].getVolumen());
                resto -= materiales[materialMaximo].getVolumen();
            }else{
                solucion[materialMaximo].setVolumenUsado(resto);
                resto = 0;
            }
        }

    }while(resto != 0 && materialDisponible);
}

void escribirSolucion(vector<MaterialUsado> &solucion){
    float precioFinal = 0;

    cout << endl << "Solucion: " << endl;
    for(MaterialUsado mu: solucion){
        if(mu.getVolumenUsado() != 0){
            precioFinal += mu.getMaterial().getPrecio();
            cout << "Material " << mu.getMaterial().getEtiqueta() << ", volumen: " << mu.getVolumenUsado() << endl;
        }
    }

    cout << endl << "Precio total mochila: " << precioFinal << endl << endl;
}