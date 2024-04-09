#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include<stdlib.h> //libreria para new y delete:
#include<algorithm> //libreria utilizada en hallarTamanoDeMatrices, usando la funcion max(a,b)

using namespace std;

#endif // FUNCIONES_H

//PROTOTIPO DE LAS FUNCIONES

void pedir_llave(int *&, int &);
int encontrarNumeroImparCercanoMayor(int *);
void hallarTamanoDeMatrices(int *, int , int *);
void RellenarMatrices(int ***, int , int *);
void posicionNeutra(int ***, int , int *);
void rotar(int ***, int , int *, int , int );
void hallar_valores_matrices(int ***, int , int *,int *, int , unsigned int &, unsigned int &, unsigned int &, unsigned int &);

void verificarValores(int ***, int , int *, int *, unsigned int &, unsigned int &, int , int ,unsigned int &, unsigned int &);
//Funcion principal
void comparar_Matrices(int ***, int , int *, int *, int);





