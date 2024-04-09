//MAIN:

#include"Funciones.h"

int main(){
    int *llave = nullptr; // Puntero para el arreglo dinámico de la llave
    int tamano_llave; // Tamaño actual del arreglo dinámico

    // Pedimos y almacenamos la llave
    pedir_llave(llave, tamano_llave);

    // Imprimimos la llave
    cout << "La llave ingresada es: ";
    for (int i = 0; i < tamano_llave; ++i) {
        cout << *(llave+i) << " ";
    }
    cout << endl;

    //creamos un arreglo para reservar los tamaños de las matrices
    int *puntero_tamano_matrices;

    //se declara una variable que me va a guardar el numero de matrices necesarias para el candado
    int numero_matrices= tamano_llave-1;

    //reservamos memoria dinamica para el puntero_tamano_matrices
    puntero_tamano_matrices= new int [numero_matrices];

    hallarTamanoDeMatrices(llave, tamano_llave, puntero_tamano_matrices);

    int ***puntero_candado; //punero de puntero de puntero que almacena todas las matrices que vamos a utilizar

    //crear_punteros_para_matrices(puntero_candado, numero_matrices, puntero_tamano_matrices);

    // Reservamos memoria dinámica para el triple puntero
    puntero_candado = new int **[numero_matrices];

    // Reservamos memoria dinámica para las matrices
    for (int i = 0; i < numero_matrices; i++) {
        int tamano_matriz = puntero_tamano_matrices[i]; // Obtenemos el tamaño de la matriz actual

        // Reservamos memoria dinámica para las filas y columnas de la matriz actual
        puntero_candado[i] = new int *[tamano_matriz];
        for (int j = 0; j < tamano_matriz; j++) {
            puntero_candado[i][j] = new int[tamano_matriz];
        }
    }

    //llamamos a la funcion para que nos rellene todas las matrices menos el centro
    RellenarMatrices(puntero_candado,numero_matrices,puntero_tamano_matrices);

    //llamamos a la funcion principal que nos indica cual es el candado:
    comparar_Matrices(puntero_candado,numero_matrices,puntero_tamano_matrices,llave, tamano_llave);

    for (int i = 0; i < numero_matrices; i++) {
        int tamano_matriz = *(puntero_tamano_matrices+i); // Obtenemos el tamaño de la matriz actual

        for (int fila = 0; fila < tamano_matriz; fila++) {
            delete[] puntero_candado[i][fila]; // Liberamos la memoria de cada fila de la matriz
        }
        delete[] puntero_candado[i]; // Liberamos la memoria de la matriz en sí
    }
    delete[] puntero_candado; // Liberamos la memoria del triple puntero

    //liberamos memoria dinamica para el puntero del tamaño de las matrices
    delete[] puntero_tamano_matrices;

    // Liberamos la memoria del arreglo dinámico
    delete[] llave;

    return 0;
}
