#include<stdio.h>
#include<stdlib.h>

// Defining the data like this to change data type easy if necesary
// dont forget to hcnage all scanf/printf
typedef unsigned int number;

number max(number a, number b) { return (a > b)? a : b; }
number min(number a, number b) { return (a < b)? a : b; }

number** knapSack(number W, number *wt, number *val, number n) {
    
    number i, w;

    // Se crea la matriz en el heap
    number **K = (number**) malloc((n+1) * sizeof(number*));
    
    // Se usa calloc para llenar la fila de ningun item con 0
    K[0] = (number*) calloc(W+1, sizeof(number));

    for (i = 1; i <= n; i++) {
        // Se crean cada una de las filas de la matriz
        K[i] = (number*) malloc((W+1) * sizeof(number));
        
        // Todos los elementos antes del peso del objeto son iguales a los de la fila anterior
        // Se usa min por si el peso es mas grande que la capacidad de la mochila
        number W1 = min(wt[i-1], W+1);
        for (w = 0; w < W1; w++) {
            K[i][w] = K[i-1][w];
        }

        // Una vez que se alcanza el peso del objeto
        // Se empiza a comparar si incluir el objeto genera una mayor ganancia
        for (w = W1 ; w <= W; w++) {
            K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
        }
        
    }

    return K;
    
}

void display(number **arr, number I, number J) {
    number i, j;
    for (i = 0; i <= I; i++) {
        for (j = 0; j <= J; j++) {
            printf("%u ", arr[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(number **arr, number I) {
    number i;
    for (i = 0; i <= I; i++) {
        free(arr[i]);
    }
    free(arr);
}

void printObjects(number **arr, number i, number j, number *w) {
    // Imprime los objetos que fueron tomados
    while (i > 0 && j > 0) {
        if (arr[i][j] != arr[i-1][j]) {
            printf("%u ", i );
            j -= w[i-1];
        }

        i--;
    }
        printf("\n");
}

int main() {
    number i, n, W;

    scanf("%u", &n);


    // Se crean los arreglos(en el heap) que contendran los pesos y ganacias
    number *val = (number*) malloc(n * sizeof(number)),
           *wt  = (number*) malloc(n * sizeof(number));

    // Se escanean las ganancias
    for (i = 0;i < n; ++i) {
    	scanf("%u", &val[i]);
    }
    // Se escanean los pesos
    for (i = 0;i < n; ++i) {
    	scanf("%u", &wt[i]);
    }
    

    // Se escanea la capacidad de la mochila
    scanf("%u", &W);

    // Se crea la matriz del problema
    number **solution = knapSack(W, wt, val, n);

    // Se imprime la maxima ganancia
    printf("%u\n", solution[n][W]);

    //Se imprimen los items tomados
    printObjects(solution, n, W, wt);

    // Se imprime la matriz
    display(solution, n, W);

    // //liberar memoria usada
    freeMatrix(solution, n);
    free(val);
    free(wt);

    return 0;
}