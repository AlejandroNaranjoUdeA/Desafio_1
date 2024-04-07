#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include<stdlib.h> //libreria para new y delete:
using namespace std;

#endif // FUNCIONES_H

//PROTOTIPO DE LAS FUNCIONES

void pedir_llave(int *, int);
int encontrarNumeroImparCercanoMayor(int *); //esta funcion se utiliza para ver la dimension de la primera matriz
void hallarTamanoDeMatrices(int *, int , int *);
void crear_punteros_para_matrices(int ***, int, int *);
void RellenarMatriz(int **, int);
void posicionNeutra(int **, int);
void rotar(int **, int);

string determinarSigno(int valor_K);
bool compararValores(int K[], int valores[], int tamano_K, int tamano_valores);
void liberar_memoria(int ***,int , int *);




