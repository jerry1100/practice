/*
Simple program to print out numbers in the background
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int i = 10;
    while (i) {
        printf("%d seconds left\n", i--);
        sleep(1); // pause for 1 sec
    }
    printf("Program has terminated\n");
}
