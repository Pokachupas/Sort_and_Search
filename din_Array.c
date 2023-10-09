#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *elements;
    int size;
    int cap;
}din_Array;

void init_Array(din_Array *array){
    array->size = 0;
    array->elements = calloc(1, sizeof(array->elements));
    array->cap = 1;
}
 void increase_Array(din_Array *array, int elements){
    array->elements = realloc(array->elements, (elements + array->cap) * sizeof(array->elements));
    if(array->elements != NULL){
        array->cap += elements;
    }
 }
void add_Elements(din_Array * array, int value){
    if(array->size < array->cap){
        array->elements[array->size] = value;
        array->size++; 
    }else{
        printf("Error, expanda el arreglo.");
    }
}

void show_Array(din_Array array){
    int i = 0;
    for(i = 0; i < array.size; i++){
        printf("%d ",array.elements[i]);
    }
    printf("\n");
}