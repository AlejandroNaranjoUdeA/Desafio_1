#include<iostream>
#include<stdlib.h>
using namespace std;

//IMPLEMENTACION DE LAS FUNCIONES:

//funcion que se usa por ahora, para llenar los datos de la llave en un arreglo:
void pedir_llave(int *puntero_llave, int tamano_llave){
    for(int i=0; i<tamano_llave; i++){
        cout<<"Ingrese un numero: ";
        cin>>*(puntero_llave+i);
    }
}

void hallarTamañoDeMatrices(){

}

void crear_punteros_para_matrices(int ***puntero_candado, int numero_matrices){
    int tamano_inicial_matriz = 3; //tamano inicial de la primera matriz

    //reservamos memoria dinamica para las matrices
    puntero_candado= new int **[numero_matrices];

    //reservamos memoria dinamica para las filas y columnas de cada una de las matrices
    for(int i=0; i<numero_matrices; i++){ //FILAS
        puntero_candado[i]= new int*[tamano_inicial_matriz]; //las matrices van a ser de 3x3 todas, por ahora, solo es una prueba
        for(int j=0; j<3; j++){//COLUMNAS:
            puntero_candado[i][j]= new int[tamano_inicial_matriz];
        }
    }
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


