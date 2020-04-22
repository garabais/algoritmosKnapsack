#include<stdio.h>
#include<stdlib.h>

// Defining the data like this to make migration to unsigned long long easy if necesary
// if type changed to unsigned long long  change all printf/scanf to %llu
typedef unsigned long number;

number max(number a, number b) { return (a > b)? a : b; }

number** knapSack(number W, number *wt, number *val, number n) {
    number i, w;

    number **K = (number**) malloc((n+1) * sizeof(long*));
    K[0] = (number *)calloc(W+1, sizeof(long));

    for (i = 1; i <= n; i++) {
        K[i] = (number *)malloc((W+1) * sizeof(long));
        for (w = 0; w <= W; w++) {
            if (w==0){
                K[i][w] = 0;
            } else if (wt[i-1] <= w){
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
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

int main() {
    number i, n, W;

    scanf("%lu", &n);

    number *val = (number*)malloc(n * sizeof(long)),
        *wt  = (number*)malloc(n * sizeof(long));

    for(i = 0;i < n; ++i){
    	scanf("%lu", &val[i]);
    }

    for(i = 0;i < n; ++i){
    	scanf("%lu", &wt[i]);
    }

    scanf("%lu", &W);

    number **solution = knapSack(W, wt, val, n);

    printf("%lu\n", solution[n][W]);

    display(solution, n, W);


    //TODO: mostrar items que faltan

    //liberar memoria usada
    freeMatrix(solution, n);
    free(val);
    free(wt);

    return 0;
}