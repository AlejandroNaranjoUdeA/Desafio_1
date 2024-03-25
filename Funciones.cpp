#include<iostream>
#include<stdlib.h>
using namespace std;

//IMPLEMENTACION DE LAS FUNCIONES:

int numero_filas, **puntero_matriz; //no es necesario el numero de columnas, ya que es una matriz cuadrada

void rellenarMatrices(){
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>numero_filas;


    //reservando memoria dinamica para la matriz:
    puntero_matriz= new int*[numero_filas];
    for(int i=0; i<numero_filas; i++){
        puntero_matriz[i]= new int[numero_filas];
    }


    int matriz[numero_filas][numero_filas];

    int contador=1;
    for(int i=0; i<numero_filas ; i++){
        for(int j=0; j<numero_filas; i++){
            if((*(*puntero_matriz+i)+j) == (matriz[numero_filas/2][numero_filas/2])){
                *(*(puntero_matriz+i)+j)= 0;
            }
            else{
                *(*(puntero_matriz+i)+j)= contador++;
            }
        }
    }
}

void mostrarMatrizRellena(){
    cout<<"\n\nMostrando matriz: "<<endl<<endl;
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            cout<<*(*(puntero_matriz+i)+j)<<"     ";
        }
        cout<<endl<<endl;
    }
}
