#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Defining the data like this to make migration to unsigned long long easy if necesary
// if type changed to unsigned long long  change all printf/scanf to %llu
typedef unsigned long number;

struct item {
    number n;
    number value;
    number weigth;
    double ratio;
};

int compareItems(const void *s1, const void *s2) {
    struct item *i1 = (struct item *)s1;
    struct item *i2 = (struct item *)s2;
    
    return round(i1->ratio - i2->ratio);
}

void knapSack(number W, struct item *items, number n) {
    number i, sum = 0;
    short *it = (short*) calloc(n, sizeof(short));

    qsort(items, n, sizeof(struct item), compareItems);

    
    for ( i = n; i > 0 &&  items[i-1].weigth <= W; i--) {
        it[i-1] = 1;
        sum += items[i-1].value;
        W -= items[i-1].weigth;
    }

    printf("%lu\n", sum);

    for ( i = 0; i < n; i++)
    {
        if (it[i]) {
            printf("%lu ", i);
        }
        
    }
    printf("\n");
    
    
}

int main() {
    number i, n, W;

    scanf("%lu", &n);

    struct item *items = malloc(n * sizeof(struct item));

    number *val = (number*) malloc(n * sizeof(number));

    for (i = 0;i < n; ++i) {
    	scanf("%lu", &val[i]);
    }

    for (i = 0;i < n; ++i) {
        items[i].n = i + 1;
        items[i].value = val[i];
    	scanf("%lu", &items[i].weigth);
        items[i].ratio = items[i].value/(double)items[i].weigth;
    }
    free(val);

    scanf("%lu", &W);

    knapSack(W, items, n);

    

    //liberar memoria usada
    
    free(items);

    return 0;
}