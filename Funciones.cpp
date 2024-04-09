#include"Funciones.h"

void pedir_llave(int *&llave, int &tamano){
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

int encontrarNumeroImparCercanoMayor(int *llave) {
    unsigned int num1 = *(llave); // Primer número del arreglo
    unsigned int num2 = *(llave+1); // Segundo número del arreglo

    unsigned int numeroImpar;

    if(*(llave) % 2 == 1){
        numeroImpar = *(llave);
    }
    else if(*(llave+1) % 2 == 1){
        numeroImpar= *(llave+1);
    }
    else{
        unsigned int numeroMayor = (num1 >= num2) ? num1 : num2; // Encontrar el número mayor
        numeroImpar = (numeroMayor % 2 == 0) ? numeroMayor + 1 : numeroMayor + 2; // Encontrar el próximo número impar mayor
    }

    /*
    como funciona el ?

    condicion ? valor_si_verdadero : valor_si_falso
    Donde condicion es una expresión que se evalúa como verdadera o falsa.
    Si la condicion es verdadera, la expresión ternaria devuelve valor_si_verdadero; de lo contrario, devuelve valor_si_falso
    */

    return numeroImpar;
}

void hallarTamanoDeMatrices(int *llave, int tamano_llave, int *puntero_tamano_matrices) {

    /*Se va a determinar el tamaño de las matrices mediante las siguientes condiciones:

    1) Si el valor de la matriz 1 tiene que ser mayor que el de la matriz 2, quiere decir que el tamaño de 1 tiene que ser mayor que el de 2
    2) Si el valor de la matriz 2 tiene que ser menor que el de la matriz 3, quiere decir que el tamaño de 2 tiene que ser menor que 3 y que 3 puede ser igual
    o mayor que 1
    3) Si el valor de la matriz 3 tiene que ser mayor que el de la matriz 4, quiere decir que el tamaño de 3 tiene que ser mayor que 4 y 4 tiene que ser igual
    o menor que 2

    Todo esto se hace ya que, si la matriz que necesitamos requiere un valor mayor, por obligacion esta tiene que tener mayor dimension ya que posee valores
    mas grandes
    */

    int matrizA= encontrarNumeroImparCercanoMayor(llave); //Hacemos llamado a la funcion e igualandola a matrizA

    *(puntero_tamano_matrices) = matrizA; // llenamos la primera posicion con el valor de matrizA

    int matrizB = 0; // Inicializamos matrizB con el valor de la segunda matriz


    for(int i = 2; i < tamano_llave ; i++) { // Recorremos hasta el penúltimo elemento de puntero_llave
        if(*(llave+i) == 1) {
            matrizB = max(matrizA - 2, *(puntero_tamano_matrices)); // Si puntero_llave[i] es 1, matrizA debe ser mayor que matrizB o debe ser el primer tamano de la primera matriz, ya que esta este es el minimo tamaño de una matriz para la posicion que nos dan
        }
        else if(*(llave+i) == -1) {
            matrizB = max(matrizA + 2, *(puntero_tamano_matrices)); // Si puntero_llave[i] es -1, matrizA debe ser menor que matrizB o debe ser el primer tamano de la primera matriz, ya que esta este es el minimo tamaño de una matriz para la posicion que nos dan
        }
        // Si puntero_llave[i] es 0, no hacemos cambios en las matrices
        else if(*(llave+i) == 0) {
            // No se hacen cambios en las matrices, matrizA y matrizB conservan sus valores anteriores
        }

        matrizA = matrizB; // Ahora matrizA toma el valor de matrizB para el siguiente ciclo
        *(puntero_tamano_matrices + i - 1) = matrizB; // Guardamos el valor de matrizB en el arreglo de tamaños
    }
}


void RellenarMatrices(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices){
    for (int k = 0; k < numero_matrices; k++) { // Iterar sobre cada matriz
        int tamano_matriz = *(puntero_tamano_matrices+k); // Obtener el tamaño de la matriz actual
        int centro = tamano_matriz / 2; // Calcular el índice del centro de la matriz

        // Rellenar la matriz actual con números del 1 al tamaño de la matriz
        int contador = 1;
        for (int i = 0; i < tamano_matriz; i++) { //
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
/*
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
*/

void rotar(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices, int k, int contador){
    // Transponer matriz
    int tamano = *(puntero_tamano_matrices + k + 1);
    for(int i=0; i<tamano; i++){
        for(int j=i+1; j<tamano; j++){
            swap(*(*(*(puntero_candado + k+1) + i) + j), *(*(*(puntero_candado + k) + j) + i));
        }
    }
    //cambia las filas, la primera por la ultima, la segunda con la penultima, la tercera con la antepenultima, etc
    //es decir, 1 la cambia por n-1, la 2 por n-2, etc.

    // Cambiar las filas, la primera por la ultima, la segunda por la penultima, etc.
    for(int i=0; i<tamano/2; i++){
        swap(*(*(puntero_candado + k + 1) + i), (*(*(puntero_candado + k + 1) + tamano - i - 1)));

    }

    //mostramos en consola para ver si esta buena la rotacion:

    if(contador==1 || contador==2 ||contador==3){
        cout<<"\nRotando la matriz "<<k + 2<<" en rotacion "<<contador<<endl<<endl;
    }
}



void hallar_valores_matrices(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices,int *llave, int k, unsigned int &fila_segunda_matriz, unsigned int &columna_segunda_matriz, unsigned int &valor1, unsigned int &valor2){

    if(k==0){ //en caso de que estemos trabajando con la primera matriz: se sacan la fila y la columna que nos dan en *llave

        //si el tamano de la matrizA es menor que el de la matriz B:
        if(*(puntero_tamano_matrices+k) < *(puntero_tamano_matrices + k + 1)){

            //HALLAMOS LAS POSICIN FILA Y COLUMNA

            //hallamos la posicion de fila de la segunda matriz como:
            //fila_segunda_matriz= fila_primera_matriz + (tamano_segunda_matriz - tamano_primera_matriz) / 2
            fila_segunda_matriz= (*(llave+k) + ((*(puntero_tamano_matrices+ k + 1))-(*(puntero_tamano_matrices + k))) / 2);

            //hallamos la posicion de columna de la segunda matriz como:
            ////columa_segunda_matriz= columna_primera_matriz + (tamano_segunda_matriz - tamano_primera_matriz) / 2
            columna_segunda_matriz= (*(llave+ k + 1) + ((*(puntero_tamano_matrices+ k + 1)) - (*(puntero_tamano_matrices + k))) / 2);

            //HALLAMOS EL VALOR DE LA MATRIZ

            //calculamos el primer valor de la primera matriz como:
            //aclaracion, esta solo es de la primera matriz, las otras no.
            //valor1= *(*(*(puntero_candado+k)+fila_primera_matriz)+ columna_primera_matriz)
            valor1= *(*(*(puntero_candado + k)+ *(llave+k) - 1)+ *(llave + k + 1) - 1); //se agrega el -1 ya que empezamos las posiciones desde 1 y no desde 0

            //calculamos el valor de la segunda matriz:
            valor2= *(*(*(puntero_candado + k + 1)+fila_segunda_matriz - 1)+columna_segunda_matriz - 1);
        }

        //si el tamano de la matriz A es mayor que el de la matriz B:
        else if(*(puntero_tamano_matrices+k) > *(puntero_tamano_matrices + k + 1)){

            //HALLAMOS LAS POSICIN FILA Y COLUMNA

            //hallamos la posicion de la fila de la segunda_matriz como:
            //fila_segunda_matriz= tamano_segunda_matriz / 2 -((tamano_primera_matriz/2) - fila_primera_matriz)
            fila_segunda_matriz= (*(puntero_tamano_matrices + k + 1) / 2 - ((*(puntero_tamano_matrices+k) / 2) - *(llave+k))) ;

            //hallamos la posicion de la columna de la segunda matriz como:
            //columa_segunda_matriz= tamano_segunda_matriz / 2 -((tamano_primera_matriz/2) - columna_primera_matriz)
            columna_segunda_matriz= (*(puntero_tamano_matrices + k + 1) / 2 - ((*(puntero_tamano_matrices+k) / 2) - *(llave + k + 1)));

            //HALLAMOS EL VALOR DE LA MATRIZ

            //calculamos el primer valor de la primera matriz como:
            //aclaracion, esta solo es de la primera matriz, las otras no.
            //valor1= *(*(*(puntero_candado+k)+fila_primera_matriz)+ columna_primera_matriz)
            valor1= *(*(*(puntero_candado + k)+ *(llave+k) - 1)+ *(llave + k + 1) - 1);

            //calculamos el valor de la segunda matriz:
            valor2= *(*(*(puntero_candado + k + 1) + fila_segunda_matriz - 1)+columna_segunda_matriz - 1);
        }

        //si el tamano de la matriz A es igual que el de la matriz B:
        else if(*(puntero_tamano_matrices+k) == *(puntero_tamano_matrices + k + 1)){

            fila_segunda_matriz= *(llave+k);
            columna_segunda_matriz = *(llave + k + 1);

            //calculamos el primer valor de la primera matriz como:
            //aclaracion, esta solo es de la primera matriz, las otras no.
            //valor1= *(*(*(puntero_candado+k)+fila_primera_matriz)+ columna_primera_matriz)
            valor1= *(*(*(puntero_candado + k)+ *(llave+k) - 1)+ *(llave + k + 1) - 1);

            //calculamos el valor de la segunda matriz:
            valor2= *(*(*(puntero_candado + k + 1)+fila_segunda_matriz - 1)+columna_segunda_matriz - 1);

        }
    }

    //en caso de que k sea mayor a 0:
    else if(k>0){

        //cambiamos los valores de fila_segunda_matriz para fila_primera_matriz, lo mismo con la columna
        unsigned int fila_primera_matriz = fila_segunda_matriz;
        unsigned int columna_primera_matriz = columna_segunda_matriz;

        valor1= valor2;

        //si el tamano de la matrizA es menor que el de la matriz B:
        if(*(puntero_tamano_matrices+k) < *(puntero_tamano_matrices + k + 1)){

            //HALLAMOS LAS POSICIN FILA Y COLUMNA

            //hallamos la posicion de fila de la segunda matriz como:
            //fila_segunda_matriz= fila_primera_matriz + (tamano_segunda_matriz - tamano_primera_matriz) / 2
            fila_segunda_matriz= (fila_primera_matriz + ((*(puntero_tamano_matrices+ k + 1))-(*(puntero_tamano_matrices + k))) / 2);

            //hallamos la posicion de columna de la segunda matriz como:
            ////columa_segunda_matriz= columna_primera_matriz + (tamano_segunda_matriz - tamano_primera_matriz) / 2
            columna_segunda_matriz= (columna_primera_matriz + ((*(puntero_tamano_matrices+ k + 1)) - (*(puntero_tamano_matrices + k))) / 2);

            //HALLAMOS EL VALOR DE LA MATRIZ B:

            //calculamos el valor de la segunda matriz:
            valor2= *(*(*(puntero_candado + k + 1)+fila_segunda_matriz- 1)+columna_segunda_matriz - 1);
        }

        //si el tamano de la matriz A es mayor que el de la matriz B:
        else if(*(puntero_tamano_matrices+k) > *(puntero_tamano_matrices + k + 1)){

            //HALLAMOS LAS POSICIN FILA Y COLUMNA

            //hallamos la posicion de la fila de la segunda_matriz como:
            //fila_segunda_matriz= tamano_segunda_matriz / 2 -((tamano_primera_matriz/2) - fila_primera_matriz)
            fila_segunda_matriz= (*(puntero_tamano_matrices + k + 1) / 2 - ((*(puntero_tamano_matrices+k) / 2) - fila_primera_matriz));

            //hallamos la posicion de la columna de la segunda matriz como:
            //columa_segunda_matriz= tamano_segunda_matriz / 2 -((tamano_primera_matriz/2) - columna_primera_matriz)
            columna_segunda_matriz= (*(puntero_tamano_matrices + k + 1) / 2 - ((*(puntero_tamano_matrices+k) / 2) - columna_primera_matriz));

            //HALLAMOS EL VALOR DE LA MATRIZB:

            //calculamos el valor de la segunda matriz:
            valor2= *(*(*(puntero_candado + k + 1)+fila_segunda_matriz - 1)+columna_segunda_matriz - 1);
        }

        //si el tamano de la matriz A es igual que el de la matriz B:
        else if(*(puntero_tamano_matrices+k) == *(puntero_tamano_matrices + k + 1)){
            fila_segunda_matriz= fila_primera_matriz;
            columna_segunda_matriz = columna_primera_matriz;

            //calculamos el valor de la segunda matriz:
            valor2= *(*(*(puntero_candado + k + 1)+fila_segunda_matriz - 1 )+columna_segunda_matriz - 1);
        }
    }
}






// Función para verificar si los valores cumplen con las condiciones dadas por K
<<<<<<< HEAD
void verificarValores(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices, int *llave, unsigned int &valor1, unsigned int &valor2, int tamano_llave, int k,unsigned int &fila_segunda_matriz, unsigned int &columna_segunda_matriz){
=======
bool verificarValores(int K[], int valores[], int num_valores, int &valor_no_cumple1, int &valor_no_cumple2) {
    // Obtener las condiciones de K
    int num_condiciones = num_valores - 1;
    int* condiciones = K + 2;
>>>>>>> b4060e9770a3ecbcd61b7f2caabfdec46eacb0d4


<<<<<<< HEAD
    unsigned int contador = 0;
    if(*(llave+2+k)==1 ){
        while(valor1<=valor2){ // si valor 1 es menor que valor 2

            contador++;

            //llamamos a la funcion rotar
            rotar(puntero_candado, numero_matrices, puntero_tamano_matrices, k, contador);
            // se halla de nuevo las posiciones:
            hallar_valores_matrices(puntero_candado, numero_matrices, puntero_tamano_matrices, llave,k, fila_segunda_matriz, columna_segunda_matriz, valor1, valor2);

            //hacemos una condicion, si contador llega a 3, es decir, ya se roto 3 veces la matriz y no se encontro, se termina el codigo
            if(contador>3){
                cout<<"\n\nEl candado no ha sido abierto."<<endl<<endl;
                return ; // finaliza el programa
            }

        }

    }
    else if(*(llave+2+k)== -1){
        while(valor1>=valor2){ // si valor 1 es mayor que valor 2

            contador++;

            //llamamos a la funcion rotar
            rotar(puntero_candado, numero_matrices, puntero_tamano_matrices, k, contador);
            // se halla de nuevo las posiciones:
            hallar_valores_matrices(puntero_candado, numero_matrices, puntero_tamano_matrices, llave,k, fila_segunda_matriz, columna_segunda_matriz, valor1, valor2);

            //hacemos una condicion, si contador llega a 3, es decir, ya se roto 3 veces la matriz y no se encontro, se termina el codigo
            if(contador>3){
                cout<<"\n\nEl candado no ha sido abierto."<<endl<<endl;
                return ; // finaliza el programa
            }

=======
        // Verificar si se cumple la condición
        if ((condicion == 1 && valor_actual > valor_siguiente) ||
            (condicion == -1 && valor_actual < valor_siguiente) ||
            (condicion == 0 && valor_actual == valor_siguiente)) {
            continue; // Avanzar al siguiente valor
        } else {
            // Almacena los valores que no cumplen la condición y devuelve false
            valor_no_cumple1 = valor_actual;
            valor_no_cumple2 = valor_siguiente;
            return false;
>>>>>>> b4060e9770a3ecbcd61b7f2caabfdec46eacb0d4
        }
    }

    else if(*(llave+2+k)== 0){
        while(valor1!=valor2){

<<<<<<< HEAD
            contador++;

            //llamamos a la funcion rotar
            rotar(puntero_candado, numero_matrices, puntero_tamano_matrices, k, contador);
            // se halla de nuevo las posiciones:
            hallar_valores_matrices(puntero_candado, numero_matrices, puntero_tamano_matrices, llave,k, fila_segunda_matriz, columna_segunda_matriz, valor1, valor2);

            //hacemos una condicion, si contador llega a 3, es decir, ya se roto 3 veces la matriz y no se encontro, se termina el codigo
            if(contador>3){
                cout<<"\n\nEl candado no ha sido abierto."<<endl<<endl;
                return ; // finaliza el programa
            }
=======

// Función para liberar la memoria dinámica de las matrices
void liberar_memoria(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices){
    for (int i = 0; i < numero_matrices; i++){
        int tamano_matriz = *(puntero_tamano_matrices+i); // Obtenemos el tamaño de la matriz actual
>>>>>>> b4060e9770a3ecbcd61b7f2caabfdec46eacb0d4

        }

    }
}


<<<<<<< HEAD
void comparar_Matrices(int ***puntero_candado, int numero_matrices, int *puntero_tamano_matrices, int *llave, int tamano_llave){

    unsigned int fila_segunda_matriz, columna_segunda_matriz, valor1, valor2 ;

    for(int k=0; k<numero_matrices - 1; k++){ //se hace numero_matrices - 1, ya que la ultima no se compara con nada.

        // se halla la posicion para la matriz siguiente:
        hallar_valores_matrices(puntero_candado, numero_matrices, puntero_tamano_matrices, llave,k, fila_segunda_matriz, columna_segunda_matriz, valor1, valor2);

        // se comparan los 2 valores:
        verificarValores(puntero_candado, numero_matrices, puntero_tamano_matrices, llave, valor1, valor2, tamano_llave, k, fila_segunda_matriz, columna_segunda_matriz);
    }

    cout<<"\n\nEl candado para la llave ingresada es: "<<endl<<endl;
    for(int i=0; i<numero_matrices; i++){
        cout<<*(puntero_tamano_matrices+i)<<", ";
    }
}




=======

>>>>>>> b4060e9770a3ecbcd61b7f2caabfdec46eacb0d4
