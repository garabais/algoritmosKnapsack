#include<stdio.h>
#include<stdlib.h>

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

    //TODO: implementar algoritmo

    //liberar memoria usada
    
    free(val);
    free(wt);

    return 0;
}