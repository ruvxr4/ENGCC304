#include <stdio.h>

int main(){

    int num1, num2, num3, answer;

    printf("enter number: \n");

    int result = scanf("%d %d %d",&num1, &num2, &num3);

    answer = num1+num2+num3;

    if(result == 3){
        printf("the answer is: %d",answer);
    } else {
        printf("invalidi input or not enough number.\n");
    }
    return 0;
}