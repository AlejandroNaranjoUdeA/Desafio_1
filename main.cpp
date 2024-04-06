//MAIN:
#include"Funciones.h"

/**
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

    int ***puntero_candado; //triple puntero que almacena todas las matrices que vamos a utilizar

    crear_punteros_para_matrices(puntero_candado, numero_matrices);


    // esto no se deberia pedir porque lo tenemos que buscar
    unsigned int numero_filas;
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>numero_filas;

    while(numero_filas%2==0){
        cout<<"Ingrese un numero impar de filas de la matriz: ";
        cin>>numero_filas;
    }

    //LIBERACION DE LA MEMORIA DINAMICA:
    for(int i=0; i<numero_matrices; i++){
        for(int j=0; j<3; j++){
            delete[] puntero_candado[i][j];
        }
        delete[] puntero_candado[i];
    }
    delete[] puntero_candado;

    //liberamos memoria dinamica del puntero de la llave
    delete puntero_llave;

    //liberamos memoria dinamica para el puntero del tamaño de las matrices
    delete puntero_tamano_matrices;

    return 0;
}
**/
int main(){

    int *llave = nullptr; // Puntero para el arreglo dinámico de la llave
    int tamano_llave; // Tamaño actual del arreglo dinámico
    // Pedimos y almacenamos la llave
    pedir_llave(llave, tamano_llave);

    // Mostramos el tamaño del arreglo dinámico
    cout << "El tamano de la llave es: " << tamano_llave << endl;

    // Imprimimos la llave
    cout << "La llave ingresada es: ";
    for (int i = 0; i < tamano_llave; ++i) {
        cout << llave[i] << " ";
    }
    cout << endl;

    //creamos un arreglo para reservar los tamaños de las matricesÑ
    int *puntero_tamano_matrices= nullptr;

    puntero_tamano_matrices= new int;



    //se declara una variable que me va a guardar el numero de matrices necesarias para el candado
    int numero_matrices= tamano_llave -1;


    int ***puntero_candado; //triple puntero que almacena todas las matrices que vamos a utilizar

    crear_punteros_para_matrices(puntero_candado, numero_matrices);


    // esto no se deberia pedir porque lo tenemos que buscar
    unsigned int numero_filas;
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>numero_filas;

    while(numero_filas%2==0){
        cout<<"Ingrese un numero impar de filas de la matriz: ";
        cin>>numero_filas;
    }

    //LIBERACION DE LA MEMORIA DINAMICA:
    for(int i=0; i<numero_matrices; i++){
        for(int j=0; j<3; j++){
            delete[] puntero_candado[i][j];
        }
        delete[] puntero_candado[i];
    }

    // Liberamos la memoria del arreglo dinámico
    delete[] llave;


    delete[] puntero_candado;

    //liberamos memoria dinamica del puntero de la llave


    //liberamos memoria dinamica para el puntero del tamaño de las matrices
    delete puntero_tamano_matrices;

    return 0;

}





