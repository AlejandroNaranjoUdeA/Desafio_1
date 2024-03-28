#include<iostream>
#include<stdlib.h>
using namespace std;

//IMPLEMENTACION DE LAS FUNCIONES:

void RellenarMatriz(int **puntero_matriz, int numero_filas){
    int contador=1;
    for(int i=0; i<numero_filas ; i++){
        for(int j=0; j<numero_filas; j++){
            if((i==numero_filas/2) && (j==numero_filas/2)){
                //rellenar la matriz central con 0
                *(*(puntero_matriz+i)+j)= 0;
            }
            else{
                *(*(puntero_matriz+i)+j)= contador++;
            }
        }
    }
}

void estadoNeutro(int **puntero_matriz, int numero_filas){
    cout<<"\n\nMostrando matriz neutra: "<<endl<<endl;
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            if(*(*(puntero_matriz+i)+j)>=10){
                cout<<*(*(puntero_matriz+i)+j)<<"    ";

            }
            else{
                cout<<*(*(puntero_matriz+i)+j)<<"     ";

            }
        }
        cout<<endl<<endl<<endl;
    }
}

void MatrizTranspuesta(int **puntero_matriz, int numero_filas){

    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            *(*(puntero_matriz+i)+j)= *(*(puntero_matriz+j)+i);
        }
    }

    cout<<"\n\nMatriz Transpuesta: "<<endl<<endl;
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            if(*(*(puntero_matriz+i)+j)>=10){
                cout<<*(*(puntero_matriz+i)+j)<<"    ";

            }
            else{
                cout<<*(*(puntero_matriz+i)+j)<<"     ";
            }
        }
        cout<<endl<<endl<<endl;
    }
}

void estado1(int **puntero_matriz, int numero_filas){
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            swap(*(*(puntero_matriz + i) + j), *(*(puntero_matriz + numero_filas - i - 1) + j));
        }
    }

    cout<<"\n\nMostrando estado 1 de la matriz: "<<endl<<endl;
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_filas; j++){
            if(*(*(puntero_matriz+i)+j)>=10){
                cout<<*(*(puntero_matriz+i)+j)<<"    ";

            }
            else{
                cout<<*(*(puntero_matriz+i)+j)<<"     ";

            }
        }
        cout<<endl<<endl<<endl;
    }
}
