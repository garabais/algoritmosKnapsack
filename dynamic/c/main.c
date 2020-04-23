#include<stdio.h>
#include<stdlib.h>

// Defining the data like this to make migration to unsigned long long easy if necesary
// if type changed to unsigned long long  change all printf/scanf to %llu
typedef unsigned long number;

number max(number a, number b) { return (a > b)? a : b; }

number** knapSack(number W, number *wt, number *val, number n) {
    number i, w;

    number **K = (number**) malloc((n+1) * sizeof(number*));
    K[0] = (number*) calloc(W+1, sizeof(number));

    for (i = 1; i <= n; i++) {
        K[i] = (number*) malloc((W+1) * sizeof(number));
        for (w = 0; w < wt[i-1]; w++) {
            K[i][w] = K[i-1][w];
        }

        for (w = wt[i-1]; w <= W; w++) {
            K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
        }
        
    }

    return K;
    
}

void display(number **arr, number I, number J) {
    number i, j;
    for (i = 0; i <= I; i++) {
        for (j = 0; j <= J; j++) {
            printf("%lu ", arr[i][j]);
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
    
    while (i > 0 && j > 0) {
        if (arr[i][j] != arr[i-1][j]) {
            printf("%lu ", i );
            j -= w[i-1];
        }

        i--;
    }
        printf("\n");
}

int main() {
    number i, n, W;

    scanf("%lu", &n);

    number *val = (number*) malloc(n * sizeof(number)),
           *wt  = (number*) malloc(n * sizeof(number));

    for (i = 0;i < n; ++i) {
    	scanf("%lu", &val[i]);
    }

    for (i = 0;i < n; ++i) {
    	scanf("%lu", &wt[i]);
    }

    scanf("%lu", &W);

    number **solution = knapSack(W, wt, val, n);

    printf("%lu\n", solution[n][W]);

    //DONE: mostrar items que faltan
    printObjects(solution, n, W, wt);

    display(solution, n, W);

    //liberar memoria usada
    freeMatrix(solution, n);
    free(val);
    free(wt);

    return 0;
}