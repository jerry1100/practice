/*
Testing realloc() by dynamically allocating more memory to append element to array
*/

#include <stdio.h>
#include <stdlib.h>

int *create_array(int size);
// Given: the size of the array to be created
// Returns: pointer to head of created array

void append_array(int *arr, int *size, int num);
// Given: pointer to head of array, size of array, and integer to append
// Appends integer to end of array and updates size

void print_array(int *arr, int size, int flag);
// Given: pointer to head of array, size of array
// Prints out the contents of the array, including addresses if flag is set to 1

int main() {
    int size = 0;
    int *arr = create_array(size);

    for (;;) {
        printf("\nYour array: ");
        print_array(arr, size, 0);

        // Get command
        char cmd;
        printf("(a)dd element, (s)how addresses, (c)lear array: ");
        scanf("%c", &cmd);

        // Process command
        if (cmd == 'a') {
            printf("Enter a number to add to the array: ");
            int num;
            scanf("%d", &num);
            append_array(arr, &size, num);
        } else if (cmd == 's') {
            printf("Array elements and addresses: \n");
            print_array(arr, size, 1);
        } else if (cmd == 'c') {
            free(arr);
            size = 0;
            printf("Array cleared\n");
            arr = create_array(size);
        }

        while (getchar() != '\n'); // flush out buffer
    }
}

int *create_array(int size) {
    return (int *) malloc(size*sizeof(int));
}

void append_array(int *arr, int *size, int num) {
    arr = (int *) realloc(arr, (*size+1)*sizeof(int)); // allocate more memory
    arr[*size] = num; // append element to array
    *size += 1;
}

void print_array(int *arr, int size, int flag) {
    int i;

    if (flag) { // print out elements and addresses
        printf("{\n");
        for (i = 0; i < size; i++) {
            printf("\t%p: %d\n", arr+i, arr[i]);
        }
        printf("}\n");
    } else { // print just elements
        printf("{");
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n");
    }
}
