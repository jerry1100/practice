/*
Simple program to print out numbers in the background
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int i = 0;

    for (;;) {
        printf("%d\n", i++);
        sleep(1); // pause for 1 sec
    }
}
