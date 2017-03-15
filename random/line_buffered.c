/*
Desmontrates differences between line buffering and no buffering.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int i;

    // Try to print with line buffering turned on
    printf("Line buffering: output is buffered until newline (wait 10s)\n");
    for (i = 0; i < 10; i++) {
        sleep(1);
        printf("%d ", i);
    }
    putchar('\n');

    // Turn off line buffering and try again
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("No line buffering: output is printed right away\n");
    for (i = 0; i < 10; i++) {
        sleep(1);
        printf("%d ", i);
    }
    putchar('\n');
}
