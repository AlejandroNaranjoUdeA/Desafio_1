#include<iostream>
#include<stdlib.h>
using namespace std;

//IMPLEMENTACION DE LAS FUNCIONES:

int numero_filas, **puntero_matriz; //no es necesario el numero de columnas, ya que es una matriz cuadrada

void rellenarMatrices(){
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>numero_filas;

    while(numero_filas%2==0){
        cout<<"Ingrese un numero impar de filas de la matriz: ";
        cin>>numero_filas;
    }


    //reservando memoria dinamica para la matriz:
    puntero_matriz= new int*[numero_filas];
    for(int i=0; i<numero_filas; i++){
        puntero_matriz[i]= new int[numero_filas];
    }

    int contador=1;
    for(int i=0; i<numero_filas ; i++){
        for(int j=0; j<numero_filas; j++){
            if((i==numero_filas/2) && (j==numero_filas/2)){
                *(*(puntero_matriz+i)+j)= 0;
            }
            else{
                *(*(puntero_matriz+i)+j)= contador++;
            }
        }
    }
}

void mostrarMatrizRellena(){
    cout<<"\n\nMostrando matriz "<<numero_filas<<"X"<<numero_filas<<endl<<endl;
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            if(*(*(puntero_matriz+i)+j)>=10){
                cout<<*(*(puntero_matriz+i)+j)<<"    ";
            }
            else{
                cout<<*(*(puntero_matriz+i)+j)<<"     ";
            }
        }
        cout<<endl<<endl;
    }
}
