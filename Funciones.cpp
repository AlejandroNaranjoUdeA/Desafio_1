#include"Funciones.h"

//IMPLEMENTACION DE LAS FUNCIONES
//funcion que se usa por ahora, para llenar los datos de la llave en un arreglo

void pedir_llave(int *puntero_llave, int tamano_llave){
    for(int i=0; i< tamano_llave; i++){
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




// Función para determinar el signo de acuerdo al valor de K
string determinarSigno(int valor_K) {
    if (valor_K < 0) {
        return "<";
    } else {
        return ">";
    }
}

// Función para comparar los valores según las reglas dadas por K
bool compararValores(int K[], int valores[], int tamano_K, int tamano_valores) {
    if (tamano_valores != tamano_K - 1) {
        cerr << "Error: El número de valores debe ser igual al número de elementos en K - 1." << endl;
        return false;
    }

    string signo_actual = determinarSigno(K[2]); // Signo del primer valor de K
    int index_valores = 0;

    for (int i = 0; i < tamano_K - 1; i += 2) {
        int valor_K = K[i + 1];
        string signo = determinarSigno(valor_K);

        if (signo != signo_actual) {
            return false;
        }

        signo_actual = (signo_actual == ">") ? "<" : ">"; // Alternamos el signo

        // Se verifica si se cumplen las condiciones con los valores dados
        if (!((signo == ">" && valores[index_valores] > valores[index_valores + 1]) ||
              (signo == "<" && valores[index_valores] < valores[index_valores + 1]))) {
            return false;
        }

        index_valores++;
    }

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
 funcion para saber si la llave abrer el candado dependiendo de los valores y de k
int main() {
    // Supongamos que ya tienes el arreglo K y los valores A, B, C y D
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

    return 0;
}

**/

/*
for(int k=0; k<4; k++){ //la
    for(int i=0; i<numero_filas; i++){
        for(int j=0; j<numero_columnas; j++)
            *(*(*(puntero+k)+i)+j);
*/
