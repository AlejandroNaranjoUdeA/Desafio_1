#include<iostream>
#include<stdlib.h>
using namespace std;

//IMPLEMENTACION DE LAS FUNCIONES:

//funcion que se usa por ahora, para llenar los datos de la llave en un arreglo:
void pedir_llave(int * puntero_llave, int tamano_llave){
    for(int i=0; i<tamano_llave; i++){
        cout<<"Ingrese un numero: ";
        cin>>*(puntero_llave+i);
    }
}

void crear_punteros_para_matrices(int numero_matrices){
    int tamano = 3; //tamano inicial de la primera matriz

}


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

void posicionNeutra(int **puntero_matriz, int numero_filas){
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


void rotar(int **puntero_matriz, int numero_filas){

    //transponer matriz:
    for(int i=0; i<numero_filas; i++){
        for(int j=i+1; j<numero_filas; j++){
            int temp = *(*(puntero_matriz + i) + j);
            *(*(puntero_matriz + i) + j) = *(*(puntero_matriz + j) + i);
            *(*(puntero_matriz + j) + i) = temp;        }
    }

    for(int i=0; i<numero_filas/2; i++){
        swap(*(puntero_matriz + i), *(puntero_matriz + numero_filas - i - 1));
    }

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


