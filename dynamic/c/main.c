#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) { return (a > b)? a : b; }

int** knapSack(size_t W, int *wt, int *val, size_t n) {
    size_t i, w;

    int **K = (int**) malloc((n+1) * sizeof(int*));
    K[0] = (int *)calloc(W+1, sizeof(int));

    for (i = 1; i <= n; i++) {
        K[i] = (int *)malloc((W+1) * sizeof(int));
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

void display(int **arr, size_t I, size_t J) {
    size_t i, j;
    for (i = 0; i <= I; i++) {
        for (j = 0; j <= J; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **arr, size_t I) {
    size_t i;
    for (i = 0; i <= I; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    size_t i, n, W;

    scanf("%d", &n);

    int *val = (int*)malloc(n * sizeof(int)),
        *wt  = (int*)malloc(n * sizeof(int));

    for(i = 0;i < n; ++i){
    	scanf("%d", &val[i]);
    }

    for(i = 0;i < n; ++i){
    	scanf("%d", &wt[i]);
    }

    scanf("%d", &W);

    int **solution = knapSack(W, wt, val, n);

    printf("%d\n", solution[n][W]);

    display(solution, n+1, W);

    //TODO: mostrar items que faltan

    //liberar memoria usada
    freeMatrix(solution, n+1);
    free(val);
    free(wt);

    return 0;
}