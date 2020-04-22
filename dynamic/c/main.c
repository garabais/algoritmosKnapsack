#include<stdio.h>
#include<stdlib.h>

#define lu unsigned long

lu max(lu a, lu b) { return (a > b)? a : b; }

lu** knapSack(lu W, lu *wt, lu *val, lu n) {
    lu i, w;

    lu **K = (lu**) malloc((n+1) * sizeof(long*));
    K[0] = (lu *)calloc(W+1, sizeof(long));

    for (i = 1; i <= n; i++) {
        K[i] = (lu *)malloc((W+1) * sizeof(long));
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

void display(lu **arr, lu I, lu J) {
    lu i, j;
    for (i = 0; i <= I; i++) {
        for (j = 0; j <= J; j++) {
            printf("%lu ", arr[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(lu **arr, lu I) {
    lu i;
    for (i = 0; i <= I; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    lu i, n, W;

    scanf("%lu", &n);

    lu *val = (lu*)malloc(n * sizeof(long)),
        *wt  = (lu*)malloc(n * sizeof(long));

    for(i = 0;i < n; ++i){
    	scanf("%lu", &val[i]);
    }

    for(i = 0;i < n; ++i){
    	scanf("%lu", &wt[i]);
    }

    scanf("%lu", &W);

    lu **solution = knapSack(W, wt, val, n);

    printf("%lu\n", solution[n][W]);

    display(solution, n, W);


    //TODO: mostrar items que faltan

    //liberar memoria usada
    freeMatrix(solution, n);
    free(val);
    free(wt);

    return 0;
}