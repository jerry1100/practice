#include <stdio.h>

int addDigits(int num);
// Given: a positive integer
// Returns: resulting integer from summing digits until sum is a single digit

int main() {
    int testNum;

    for (;;) {
        printf("Enter a number: ");
        scanf("%d", &testNum);
        printf("You entered: %d, result: %d\n\n", testNum, addDigits(testNum));
    } 
}

int addDigits(int num) {
    int sum = 0;
    while (num) { // sum up num's digits
        sum += num % 10;
        num /= 10;
    }
    
    if (sum > 9) {
        return addDigits(sum); // sum up sum's digits
    }
    return sum;
}
