#include<stdio.h>
#include<stdlib.h>

unsigned long max(unsigned long a, unsigned long b) { return (a > b)? a : b; }

unsigned long** knapSack(unsigned long W, unsigned long *wt, unsigned long *val, unsigned long n) {
    unsigned long i, w;

    unsigned long **K = (unsigned long**) malloc((n+1) * sizeof(long*));
    K[0] = (unsigned long *)calloc(W+1, sizeof(long));

    for (i = 1; i <= n; i++) {
        K[i] = (unsigned long *)malloc((W+1) * sizeof(long));
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

void display(unsigned long **arr, unsigned long I, unsigned long J) {
    unsigned long i, j;
    for (i = 0; i <= I; i++) {
        for (j = 0; j <= J; j++) {
            printf("%lu ", arr[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(unsigned long **arr, unsigned long I) {
    unsigned long i;
    for (i = 0; i <= I; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    unsigned long i, n, W;

    scanf("%lu", &n);

    unsigned long *val = (unsigned long*)malloc(n * sizeof(long)),
        *wt  = (unsigned long*)malloc(n * sizeof(long));

    for(i = 0;i < n; ++i){
    	scanf("%lu", &val[i]);
    }

    for(i = 0;i < n; ++i){
    	scanf("%lu", &wt[i]);
    }

    scanf("%lu", &W);

    unsigned long **solution = knapSack(W, wt, val, n);

    printf("%lu\n", solution[n][W]);

    display(solution, n, W);


    //TODO: mostrar items que faltan

    //liberar memoria usada
    freeMatrix(solution, n);
    free(val);
    free(wt);

    return 0;
}