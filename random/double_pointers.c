/*
Testing various applications of double pointers
*/

#include <stdio.h>

void changePointerSingle(int *p, int *num);
// Given: two integer pointers
// Will update the first pointer to point to the second

void changePointerDouble(int **p, int *num);
// Given: a double pointer and an integer pointer
// Updates dereferenced pointer to point to the number

int main() {
    // See how they are related
    int num = 5;
    int *sp = &num;
    int **dp = &sp;
    printf("Relation of single and double pointers:\n");
    printf("&num: %p, num: %d\n", &num, num);
    printf("&sp: %p, sp: %p, *sp: %d\n", &sp, sp, *sp);
    printf("&dp: %p, dp: %p, *dp: %p **dp: %d\n", &dp, dp, *dp, **dp);
    printf("\n");

    // Change pointer using single pointer
    int num1 = 4;
    int num2 = 16;
    int *p1 = &num1;
    printf("Changing pointer using single pointer:\n");
    printf("Before:\t&p: %p, p: %p, *p: %d\n", &p1, p1, *p1);
    changePointerSingle(p1, &num2);
    printf("After:\t&p: %p, p: %p, *p: %d\n", &p1, p1, *p1);
    printf("\n");

    // Change pointer using double pointer
    int num3 = 4;
    int num4 = 16;
    int *p2 = &num3;
    printf("Changing pointer using double pointer:\n");
    printf("Before:\t&p: %p, p: %p, *p: %d\n", &p2, p2, *p2);
    changePointerDouble(&p2, &num2);
    printf("After:\t&p: %p, p: %p, *p: %d\n", &p2, p2, *p2);
}

void changePointerSingle(int *q, int *num) {
    printf("Enter:\t&q: %p, q: %p, *q: %d\n", &q, q, *q);
    q = num;
    printf("Exit:\t&q: %p, q: %p, *q: %d\n", &q, q, *q);
}

void changePointerDouble(int **q, int *num) {
    printf("Enter:\t&q: %p, q: %p, *q: %p\n", &q, q, *q);
    *q = num;
    printf("Exit:\t&q: %p, q: %p, *q: %p\n", &q, q, *q);
}
