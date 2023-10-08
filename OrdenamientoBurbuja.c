#include <stdio.h>
#include <stdlib.h>

struct din_Array;

typedef struct{
    int *elements;
    int size;
    int cap;
}din_Array;

void bubbleSort(din_Array *array);

void init_Array(din_Array *array);
void increase_Array(din_Array *array, int elements);
void add_Elements(din_Array * array, int value);
void show_Array(din_Array array);



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

    bubbleSort(arr);

    show_Array(array);

}

void bubbleSort(din_Array *array){
    int i,j,temp;
    for(i= 0; i < array->size; i++){
        temp = array->elements[0];
        for(j = 0; j < array->size-1; j++){
            if(temp > array->elements[j + 1]){
                array->elements[j] = array->elements[j + 1];
                array->elements[j + 1] = temp;
            }else{
                temp = array->elements[j + 1];
            }
        }
    }
}

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


