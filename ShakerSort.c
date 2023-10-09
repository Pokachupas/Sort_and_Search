#include <stdio.h>
#include <stdlib.h>
#include "din_Array.h"

void shakerSort(din_Array *array);

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
    printf("%d\n", array.size);
    show_Array(array);

    sha(arr);

    show_Array(array);

}

void shakerSort(din_Array *array){
    int swap = 1;
    int i;
    int value = 0;
    int count;
    while(swap > 0){
        int temp;
        temp = array->elements[value];
        count = 0;
        for(i = value; i < array->size - 1; i++){
            if(temp > array->elements[i + 1]){
                array->elements[i] = array->elements[i + 1];
                array->elements[i + 1] = temp;
                value = i;
                count++;
            }else{
                break;
            }
        }
        temp = array->elements[value];
        for(i = value; i > 0; i--){
            if(temp < array->elements[i - 1]){
                array->elements[i] = array->elements[i - 1];
                array->elements[i - 1] = temp;
                value = i;
                count++;
            }else{
                break;
            }
        }
        if(count == 0){
            swap = 0;
        }
    }
}
