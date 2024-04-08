#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include<stdlib.h> //libreria para new y delete:
using namespace std;

#endif // FUNCIONES_H

//PROTOTIPO DE LAS FUNCIONES

void pedir_llave(int *&, int &);
int encontrarNumeroImparCercanoMayor(int *); //esta funcion se utiliza para ver la dimension de la primera matriz
void hallarTamanoDeMatrices(int *, int , int *);
void RellenarMatrices(int ***, int , int *);
void posicionNeutra(int ***, int , int *);
void rotar(int **, int);
void hallar_posiciones_matrices(int ***, int, int *,int *);

bool verificarValores(int, int , int , int &, int &);

void liberar_memoria(int ***,int , int *);




