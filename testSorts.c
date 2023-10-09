#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(){
    din_Array array;
    din_Array* arr = &array;
    init_Array(arr);
    int i = 1, temp = 0;
    while(temp != -1){
        printf("Ingrese numeros para ordenar.\n Presione -1 para parar.\n");
        scanf("%d",&temp);
        if(temp != -1){
            increase_Array(arr,1);
            add_Elements(arr,temp);
        }
    }
    show_Array(array);

    // bubbleSort(arr);
    // shakerSort(arr);
    // selectionSort(arr);
    directInsertionSort(arr);
    show_Array(array);
    
}






