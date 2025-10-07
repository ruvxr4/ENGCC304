#include <stdio.h>
#include <stdbool.h>

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }//end for
    return result;
}//end power fuction

bool isArmstrong(int num) {
    if (num < 0) {
        return false;
    }//end if

    int originalNum = num;
    int sum = 0;
    int n = 0;

    int temp = originalNum;
    if (temp == 0) {
        n = 1;
    } else {
        while (temp != 0) {
            temp /= 10;
            ++n;
        }//end while
    }//end if-else

    
    temp = originalNum;
    while (temp != 0) {
        int digit = temp % 10;
        sum += power(digit, n);
        temp /= 10;
    }//end while

    
    return (sum == originalNum);
}//end fuction

int main() {
    int number;

    printf("Enter Number:\n");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }//end if-else

    return 0;
}//end main