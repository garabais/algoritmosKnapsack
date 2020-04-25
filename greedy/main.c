#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Defining the data like this to make migration to unsigned long long easy if necesary
// if type changed to unsigned long long  change all printf/scanf to %llu
typedef unsigned long long number;

// Struct que guardara toda la informacion
struct item {
    number n;
    number value;
    number weigth;
    double ratio;
};

// Funcion de comparacion que sirve para ordenar los structs en base al ratio 
int compareItems(const void *s1, const void *s2) {
    struct item *i1 = (struct item *)s1;
    struct item *i2 = (struct item *)s2;
    
    return round(i1->ratio - i2->ratio);
}

void knapSack(unsigned long long W, struct item *items, unsigned long long n) {
    number i, sum = 0;

    // Arreglo que guarda que items fueron selecionados
    short *it = (short*) calloc(n, sizeof(short));

    // se ordena el arreglo se items basandose en el ratio
    qsort(items, n, sizeof(struct item), compareItems);


    // Se toman los items con mayor ratio hasta que ya no quepan    
    for ( i = n; i > 0 &&  items[i-1].weigth <= W; i--) {
        it[i-1] = 1;
        sum += items[i-1].value;
        W -= items[i-1].weigth;
    }

    // Imprimimos la ganancia obtenida
    printf("%llu\n", sum);


    // Imprimimos los items tomados
    for ( i = 0; i < n; i++)
    {
        if (it[i]) {
            printf("%llu ", i);
        }
        
    }
    printf("\n");
    
    
}

int main() {

    number i, n, W;

    scanf("%llu", &n);

    struct item *items = malloc(n * sizeof(struct item));

    number *val = (number*) malloc(n * sizeof(number));

    for (i = 0;i < n; ++i) {
    	scanf("%llu", &val[i]);
    }

    // Se crean los structs, se calcula el ratio y se guardan en el arreglo de structs
    for (i = 0;i < n; ++i) {
        items[i].n = i + 1;
        items[i].value = val[i];
    	scanf("%llu", &items[i].weigth);
        items[i].ratio = items[i].value/(double)items[i].weigth;
    }

    scanf("%llu", &W);

    // solucion del problema
    knapSack(W, items, n);

    

    //liberar memoria usada
    
    free(val);
    
    free(items);

    return 0;
}