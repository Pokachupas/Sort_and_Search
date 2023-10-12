#include "din_Array.h"

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
                temp = array->elements[i + 1];
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
                array->elements[i - 1];
            }
        }
        if(count == 0){
            swap = 0;
        }
    }
}

void selectionSort(din_Array *array){
    int i, j;
    int temp, count = 0;
    for(i = 0; i < array->size; i++){
        count = 0;
        temp = array->elements[i];
        for(j = i + 1; j < array->size; j++){
            if(temp > array->elements[j]){
                temp = array->elements[j];
                count = j;
            }
        }
    if(count != 0){
        array->elements[count] = array->elements[i];
        array->elements[i] = temp;
    }
    }
}

void directInsertionSort(din_Array *array){
    int i,j;
    for(i = 1; i < array->size; i++){
        int temp = array->elements[i];
        int j = i - 1;
        while(j >= 0 && array->elements[j] > temp){
            array->elements[j + 1] = array->elements[j];
            j -= 1;
        }
        array->elements[j + 1] = temp;
    }
}

void binaryInsertionSort(din_Array *array){
    int i,j, temp;
    for(i = 1; i < array->size; i++){
        int left = 0;
        int right = i - 1;
        temp = array->elements[i];
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(temp < array->elements[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        for(j = i - 1; j >= left; j--){
            array->elements[j + 1] = array->elements[j]; 
        }
        array->elements[left] = temp;
    }
}

// 3 2 4  1
void shellSort(din_Array *array){
    int i,j;
    int h = (array->size)/2;
    while(h >= 1){
        for(i = h; i < (array->size); i++){
            j = i - h;
            int temp = array->elements[i];
            while(j >= 0 && array->elements[j] > temp){
                array->elements[j + h] = array->elements[j];
                j -= h;
            }
            array->elements[j + h] = temp;
        }
        h /= 2;
    }
}