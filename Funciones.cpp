#include"Funciones.h"

//IMPLEMENTACION DE LAS FUNCIONES
//funcion que se usa por ahora, para llenar los datos de la llave en un arreglo


// Función para pedir la llave y almacenarla en un arreglo dinámico
void pedir_llave(int *llave, int tamano) {
    int capacidad = 5; // Capacidad inicial del arreglo dinámico
    tamano = 0; // Tamaño actual del arreglo dinámico

    llave = new int[capacidad]; // Inicializamos el arreglo dinámico

    int elemento;
    cout << "Ingrese los elementos de la llave separados por espacios, y finalice con -999: ";
    while (cin >> elemento && elemento != -999) {
        if (tamano == capacidad) {
            // Si se alcanza la capacidad máxima, redimensionamos el arreglo
            capacidad *= 2;
            int *nueva_llave = new int[capacidad];
            // Copiamos los elementos al nuevo arreglo
            for (int i = 0; i < tamano; ++i) {
                nueva_llave[i] = llave[i];
            }
            // Liberamos la memoria del arreglo antiguo
            delete[] llave;
            // Actualizamos el puntero al nuevo arreglo
            llave = nueva_llave;
        }
        // Agregamos el elemento al arreglo
        llave[tamano++] = elemento;
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

void hallarTamanoDeMatrices(int *puntero_llave, int tamano_llave, int *puntero_tamano_matrices) {

    /*Se va a determinar el tamaño de las matrices mediante las siguientes condiciones:

    1) Si el valor de la matriz 1 tiene que ser mayor que el de la matriz 2, quiere decir que el tamaño de 1 tiene que ser mayor que el de 2
    2) Si el valor de la matriz 2 tiene que ser menor que el de la matriz 3, quiere decir que el tamaño de 2 tiene que ser menor que 3 y que 3 puede ser igual
    o mayor que 1
    3) Si el valor de la matriz 3 tiene que ser mayor que el de la matriz 4, quiere decir que el tamaño de 3 tiene que ser mayor que 4 y 4 tiene que ser igual
    o menor que 2

    Todo esto se hace ya que, si la matriz que necesitamos requiere un valor mayor, por obligacion esta tiene que tener mayor dimension ya que posee valores
    mas grandes
    */

    unsigned int matrizA= encontrarNumeroImparCercanoMayor(puntero_llave); //Hacemos llamado a la funcion e igualandola a matrizA

    *(puntero_tamano_matrices) = matrizA; // llenamos la primera posicion con el valor de matrizA

    unsigned int matrizB = 0; // Inicializamos matrizB con el valor de la segunda matriz


    for(int i = 2; i < tamano_llave ; i++) { // Recorremos hasta el penúltimo elemento de puntero_llave
        if(puntero_llave[i] == 1) {
            matrizB = matrizA - 2; // Si puntero_llave[i] es 1, matrizA debe ser mayor que matrizB
        }
        else if(puntero_llave[i] == -1) {
            matrizB = matrizA + 2; // Si puntero_llave[i] es -1, matrizA debe ser menor que matrizB
        }
        // Si puntero_llave[i] es 0, no hacemos cambios en las matrices
        else if(puntero_llave[i] == 0) {
            // No se hacen cambios en las matrices, matrizA y matrizB conservan sus valores anteriores
        }

        matrizA = matrizB; // Ahora matrizA toma el valor de matrizB para el siguiente ciclo
        *(puntero_tamano_matrices + i + 1) = matrizB; // Guardamos el valor de matrizB en el arreglo de tamaños
    }
}

// Esta funcion llama a un triple puntero y reserva memoria dinamica para cada una de las matrices
/*
void crear_punteros_para_matrices(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices) {

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
}
*/

//rellena cada una de las matrices desde 1 hasta que se acaben, menos la del centro
void RellenarMatrices(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices){
    for (int k = 0; k < numero_matrices; k++) { // Iterar sobre cada matriz
        int tamano_matriz = *(puntero_tamano_matrices+k); // Obtener el tamaño de la matriz actual
        int centro = tamano_matriz / 2; // Calcular el índice del centro de la matriz

        // Rellenar la matriz actual con números del 1 al tamaño de la matriz
        int contador = 1;
        for (int i = 0; i < tamano_matriz; i++) {
            for (int j = 0; j < tamano_matriz; j++) {
                if (i == centro && j == centro) {
                    *(*(*(puntero_candado+k)+i)+j) = 0; // Colocar 0 en el centro de la matriz
                } else {
                    *(*(*(puntero_candado+k)+i)+j) = contador++; // Rellenar la matriz con números del 1 al tamaño de la matriz
                }
            }
        }
    }
}

//muestra al programador como estan quedando las matrices
void posicionNeutra(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices){

    for (int k = 0; k < numero_matrices; k++) { // Iterar sobre cada matriz
        int tamano_matriz = *(puntero_tamano_matrices + k); // Obtener el tamaño de la matriz actual

        cout << "Matriz " << k + 1 << ":" << endl; // Mostrar el número de la matriz

        // Mostrar los elementos de la matriz
        for (int i = 0; i < tamano_matriz; i++) {
            for (int j = 0; j < tamano_matriz; j++) {
                if (*(*(*(puntero_candado + k) + i) + j) >= 10) {
                    cout << *(*(*(puntero_candado + k) + i) + j) << "    ";
                } else {
                    cout << *(*(*(puntero_candado + k) + i) + j) << "     ";
                }
            }
            cout << endl <<endl <<endl;
        }
        cout << endl <<endl <<endl;
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




// Función para verificar si los valores cumplen con las condiciones dadas por K
bool verificarValores(int K[], int valores[], int num_valores) {
    // Obtener las condiciones de K
    int num_condiciones = num_valores - 1;
    int* condiciones = K + 2;

    // Verificar las condiciones
    for (int i = 0; i < num_condiciones; ++i) {
        int valor_actual = valores[i];
        int valor_siguiente = valores[i + 1];
        int condicion = condiciones[i];

        // Verificar si se cumple la condición
        if ((condicion == 1 && valor_actual > valor_siguiente) ||
            (condicion == -1 && valor_actual < valor_siguiente) ||
            (condicion == 0 && valor_actual == valor_siguiente)) {
            continue; // Avanzar al siguiente valor
        } else {
            // Mostrar el valor que no cumple con la condición y retornar falso
            cout << "El valor " << valor_actual << " y el "<<valor_siguiente<< " no cumple con la condición." << endl;
            //la idea es que en este caso se rote la matriz para buscar otro valor
            // o sea aqui ira la funcion de rotar matriz y obtener nuevos valords
            return false;

        }

    }
    // Si se llega a este punto, significa que todas las condiciones se cumplen
    return true;
}

// Función para liberar la memoria dinámica de las matrices
void liberar_memoria(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices) {
    for (int i = 0; i < numero_matrices; i++) {
        int tamano_matriz = *(puntero_tamano_matrices+i); // Obtenemos el tamaño de la matriz actual

        for (int fila = 0; fila < tamano_matriz; fila++) {
            delete[] puntero_candado[i][fila]; // Liberamos la memoria de cada fila de la matriz
        }
        delete[] puntero_candado[i]; // Liberamos la memoria de la matriz en sí
    }
    delete[] puntero_candado; // Liberamos la memoria del triple puntero
}

/**
int main() {
    int K[] = {4, 3, 0, -1, -1, 1}; // Arreglo K(4,3,1,-1,1)
    int valores[] = {7, 7, 9, 10, 7}; // Valores dados
    int num_valores = sizeof(valores) / sizeof(valores[0]);

    // Llamamos a la función para verificar los valores
    bool condicionesCumplidas = verificarValores(K, valores, num_valores);

    // Mostramos el resultado de la verificación
    if (condicionesCumplidas) {
        cout << "Los valores cumplen con las condiciones de K." << endl;
    } else {
        cout << "Los valores no cumplen con las condiciones de K." << endl;
    }

    return 0;
}
**/

/*
for(int k=0; k<4; k++){ //la
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_columnas; j++)
            *(*(*(puntero+k)+i)+j);
*/
