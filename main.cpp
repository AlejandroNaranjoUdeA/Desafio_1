//MAIN:

#include"funciones.h"
#include<iostream>
#include<stdlib.h> //libreria para new y delete:
using namespace std;

int main(){

    int numero_filas;
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>numero_filas;

    while(numero_filas%2==0){
        cout<<"Ingrese un numero impar de filas de la matriz: ";
        cin>>numero_filas;
    }

    //RESERVA DE MEMORIA DINAMICA:
    int **puntero_matriz = new int*[numero_filas];
    for(int i=0; i<numero_filas; i++){
        puntero_matriz[i]= new int[numero_filas];
    }

    RellenarMatriz(puntero_matriz, numero_filas);
    estadoNeutro(puntero_matriz, numero_filas);
    MatrizTranspuesta(puntero_matriz,numero_filas);
    estado1(puntero_matriz,numero_filas);


    //ELIMINACION DE MEMORIA DINAMICA
    for(int i=0; i<numero_filas; i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;




    return 0;
}
