//MAIN:

#include"funciones.h"
#include<iostream>
#include<stdlib.h> //libreria para new y delete:
using namespace std;

int main(){

    rellenarMatrices();
    mostrarMatrizRellena();

    //eliminando memoria dinamica:

    for(int i=0; i<numero_filas; i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;

    return 0;
}
