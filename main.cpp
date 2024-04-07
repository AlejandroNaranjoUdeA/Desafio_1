//MAIN:

#include"Funciones.h"


int main(){
    unsigned int tamano_llave;
    int *puntero_llave= nullptr; //puntero para la llave


    //creamos un arreglo para reservar los tamaños de las matricesÑ
    int *puntero_tamano_matrices= nullptr;

    puntero_tamano_matrices= new int;

    //reservamos memoria dinamica para el puntero de la llave:
    puntero_llave= new int;

    //pedimos el tamano de la llave, aclaracion: esto es temporal
    cout<<"Ingrese el tamano de la llave: ";
    cin>>tamano_llave;

    //se declara una variable que me va a guardar el numero de matrices necesarias para el candado
    int numero_matrices= tamano_llave-1;

    //pedimos la llave y la guardamos en un puntero;
    pedir_llave(puntero_llave, tamano_llave);

    hallarTamanoDeMatrices(puntero_llave, tamano_llave, puntero_tamano_matrices);

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

    RellenarMatrices(puntero_candado, numero_matrices,puntero_tamano_matrices);

    posicionNeutra(puntero_candado,numero_matrices,puntero_tamano_matrices);



    unsigned int numero_filas;
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>numero_filas;

    while(numero_filas%2==0){
        cout<<"Ingrese un numero impar de filas de la matriz: ";
        cin>>numero_filas;
    }

    liberar_memoria(puntero_candado,numero_matrices,puntero_tamano_matrices);

    for (int i = 0; i < numero_matrices; i++) {
        int tamano_matriz = *(puntero_tamano_matrices+i); // Obtenemos el tamaño de la matriz actual

        for (int fila = 0; fila < tamano_matriz; fila++) {
            delete[] puntero_candado[i][fila]; // Liberamos la memoria de cada fila de la matriz
        }
        delete[] puntero_candado[i]; // Liberamos la memoria de la matriz en sí
    }
    delete[] puntero_candado; // Liberamos la memoria del triple puntero


    //liberamos memoria dinamica del puntero de la llave
    delete puntero_llave;

    //liberamos memoria dinamica para el puntero del tamaño de las matrices
    delete puntero_tamano_matrices;
/**
    int K[] = {4, 3, -1, -1, 1}; // Esto corresponde a K(4,3,-1,-1,1)
    int valores[] = {7, 6, 8, 3}; // A=7, B=6, C=8, D=3
    int tamano_K = sizeof(K) / sizeof(K[0]);
    int tamano_valores = sizeof(valores) / sizeof(valores[0]);

    // Llamamos a la función para comparar los valores
    bool condicionesCumplidas = compararValores(K, valores, tamano_K, tamano_valores);

    // Mostramos el resultado de la comparación
    if (condicionesCumplidas) {
        cout << "Los valores cumplen con las condiciones de K." << endl;
    } else {
        cout << "Los valores no cumplen con las condiciones de K." << endl;
    }
**/
    return 0;
}

