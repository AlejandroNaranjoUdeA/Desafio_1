//MAIN:

#include"funciones.h"
#include<iostream>
#include<stdlib.h> //libreria para new y delete:
using namespace std;

int main(){

    unsigned int tamano_llave;
    int *puntero_llave= nullptr; //puntero para la llave

    //pedimos el tamano de la llave, aclaracion: esto es temporal
    cout<<"Ingrese el tamano de la llave: ";
    cin>>tamano_llave;


    //se declara una variable que me va a guardar el numero de matrices necesarias para el candado
    int numero_matrices= tamano_llave-1;

    //pedimos la llave y la guardamos en un puntero;
    pedir_llave(puntero_llave, tamano_llave);







    unsigned int numero_filas;
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




    //ELIMINACION DE MEMORIA DINAMICA
    for(int i=0; i<numero_filas; i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;




    return 0;
}
