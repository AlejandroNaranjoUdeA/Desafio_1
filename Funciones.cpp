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

int encontrarNumeroImparCercanoMayor(int *puntero_llave) {
    unsigned int num1 = *(puntero_llave); // Primer número del arreglo
    unsigned int num2 = *(puntero_llave+1); // Segundo número del arreglo

    unsigned int numeroMayor = (num1 > num2) ? num1 : num2; // Encontrar el número mayor
    unsigned int numeroImpar = (numeroMayor % 2 == 0) ? numeroMayor + 1 : numeroMayor + 2; // Encontrar el próximo número impar mayor

    /*
    como funciona el ?

    condicion ? valor_si_verdadero : valor_si_falso
    Donde condicion es una expresión que se evalúa como verdadera o falsa.
    Si la condicion es verdadera, la expresión ternaria devuelve valor_si_verdadero; de lo contrario, devuelve valor_si_falso
    */

    return numeroImpar;
}

void hallarTamanoDeMatrices(int *puntero_llave, int tamano_llave, int *puntero_tamano_matrices){
    /*Se va a determinar el tamaño de las matrices mediante las siguientes condiciones:

    1) Si el valor de la matriz 1 tiene que ser mayor que el de la matriz 2, quiere decir que el tamaño de 1 tiene que ser mayor que el de 2
    2) Si el valor de la matriz 2 tiene que ser menor que el de la matriz 3, quiere decir que el tamaño de 2 tiene que ser menor que 3 y que 3 puede ser igual
    o mayor que 1
    3) Si el valor de la matriz 3 tiene que ser mayor que el de la matriz 4, quiere decir que el tamaño de 3 tiene que ser mayor que 4 y 4 tiene que ser igual
    o menor que 2

    Todo esto se hace ya que, si la matriz que necesitamos requiere un valor mayor, por obligacion esta tiene que tener mayor dimension ya que posee valores
    mas grandes

    */

    unsigned int matrizA, matrizB; //definimos las matrices por las cuales van a ser evaluadas, estan van cambiando comforme aumentemos la posicion

    //para saber cual es la dimension de la primera matriz, nos tenemos que fijar en la posicion que nos esten dando y que esta sea mayor que la fila y columna dada
    int dimension_primera_matriz= encontrarNumeroImparCercanoMayor(puntero_llave); //Hacemos llamado a la funcion

    matrizA= *(puntero_tamano_matrices); //se definen las posiciones de las matrices;
    matrizB= *(puntero_tamano_matrices+1);

    *(puntero_tamano_matrices)= dimension_primera_matriz; //llenamos la primera posicion del arreglo de los tamanos con el tamano de la primera matriz.

    for(int i=2; i<tamano_llave; i++){ //recorremos toda el arreglo desde 2 ya que los 2 primeros valores estan reservados para la posicion de la 1ra matriz
        if(puntero_llave[i]==1){
            //si el valor de puntero_llave[i] es = 1, quiere decir que el valor de la matriz A tiene que ser mayor que el de la matriz B

        }
    }
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


