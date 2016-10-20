/*
Testing realloc() by dynamically allocating more memory to append element to array
*/

#include <stdio.h>
#include <stdlib.h>

int *createArray(int size);
// Given: the size of the array to be created
// Returns: pointer to head of created array

void appendArray(int *arr, int *size, int num);
// Given: pointer to head of array, size of array, and integer to append
// Appends integer to end of array and updates size

void printArray(int *arr, int size);
// Given: pointer to head of array, size of array
// Prints out the contents of the array

int main() {
    int size = 8;
    int *arr = createArray(size);
    int appendNum = 777; // num to append to end of array

    int i;
    for (i = 0; i < size; i++) { // fill in array with elements
        *(arr+i) = i;
    }

    printf("Before: ");
    printArray(arr, size);

    printf("After: ");
    appendArray(arr, &size, appendNum);
    printArray(arr, size);
}

int *createArray(int size) {
    return (int *) malloc(size*sizeof(int));
}

void appendArray(int *arr, int *size, int num) {
    arr = (int *) realloc(arr, (*size+1)*sizeof(int)); // allocate more memory
    *(arr+*size) = num; // append element to array
    *size += 1;
}

void printArray(int *arr, int size) {
    int i;

    printf("{");
    for (i = 0; i < size; i++) {
        printf(" %d ", *(arr+i));
    }
    printf("}\n");
}
