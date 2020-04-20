#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

int test(int t[], int n) {
    int i;
    for (i = 0; i < 20; i++)
    {
        t[i] = i;
    }
}
 
void display(int* arr, size_t size) {
    int i = 0;
   	for (i = 0; i < size; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");
}

int zeros(int* arr, size_t size) {
    int i = 0, s = 0;
   	for (i = 0; i < size; i++) {
		if (arr[i] != 0)
        {
            s++;
        }
        
	}
	printf("%d\n", s);
    
}

void wtf(int** arr, int r,int c) {
    size_t i, j;
     printf("%d, %d\n", arr, &arr);
    for (i = 0; i <  r; i++) {
        printf("%d, %d: ", arr[i], &arr[i]);
        // for (j = 0; j < c; j++) {
        //     printf("%d ", arr[i][j]);
        // }  
        printf("\n"); 
    }
}


void t(int r,  int c){
    int i, j, count; 
    printf("%d\n", &i);
  
    int (*arr)[c] = malloc(sizeof(int[r][c]));
    printf("a:%d\n",sizeof arr);
    // int (*arr)[c] = malloc(sizeof(int[r][c]));
  
    // Note that arr[i][j] is same as *(*(arr+i)+j) 
    count = 0; 
    for (i = 0; i <  r; i++) {
        for (j = 0; j < c; j++) {
            arr[i][j] = 1;
        } 
        printf("%d\n", i);
         
    }

    // printf("%d, %d\n", arr, &arr);
    // for (i = 0; i <  r; i++) {
    //     printf("%d, %d: ", arr[i], &arr[i]);
    //     for (j = 0; j < c; j++) {
    //         printf("%d ", &arr[i][j]);
    //     }  
    //     printf("\n"); 
    // }

    printf("%d, %d\n", arr, &arr);
    for (i = 0; i <  r ; i++) {
        printf("%d, %d: ", arr[i], &arr[i]);
        for (j = 0; j < c; j++) {
            printf("%d ", &arr[i][j]);
        }  
        printf("\n"); 
    }

   arr+=8;
    
    printf("%d, %d\n", arr, &arr);
    for (i = 0; i <  r - 1; i++) {
        printf("%d, %d: ", arr[i], &arr[i]);
        for (j = 0; j < c; j++) {
            printf("%d ", &arr[i][j]);
        }  
        printf("\n"); 
    }
    // wtf((int**)&arr, r, c);
       // Or *(*(arr+i)+j) = ++count 
  
    // for (i = 0; i <  r; i++) 
    //   for (j = 0; j < c; j++) 
    //      printf("%d ", arr[i][j]); 
  
    /* Code for further processing and free the  
      dynamically allocated memory */

    //   free(arr);
}


 
int main(){
    int i, j, n = 10;

    // scanf("%d", &n);
    int *ptr = (int*) malloc(n * sizeof(int));
    ptr[0] = 0;
    
    
    zeros(ptr, n);

    int (*arr) = malloc(sizeof(int[n]));

    display(arr, n);
    printf("%d, %d\n",sizeof(int*), 10*sizeof(int));
    // t(5000, 24805);
    // t(5000, 24805);
    t(20,10);

    
    // display(ptr, SIZE);
    // test(ptr, SIZE);
    // display(ptr, SIZE);
    // memset(ptr, 0, SIZE*sizeof(int));
    // display(ptr, SIZE);

    // int array[5] = { 1, 2, 3, 4, 5 };
    // size_t size = (sizeof(array) / sizeof(int));
    
    // display(array, size);
	// //*****MEMSET*****//
	// memset(array, 0, sizeof(array));
    // display(array, size);
	
	// printf("%d, %d, %d",sizeof(array), sizeof(ptr), sizeof(*ptr));

    
    
    free(ptr);
    return 0;
}
