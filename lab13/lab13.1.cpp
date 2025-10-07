#include <stdio.h>

void swapnum(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


int main(){
    int num1, num2 ;
    int *ptr1 = &num1;
    int *ptr2 = &num2 ;

    printf("enter num1: \n");
    scanf("%d",&num1);
    printf("enter num2: \n");
    scanf("%d",&num2);

    printf("before swap: num1 = %d,num2 = %d\n",num1, num2);

    swapnum(ptr1,ptr2); //a จะชี้ไปที่num1,bจะชึ้ไปnum2

    printf("after swap: num1 = %d,num2 = %d\n",num1, num2);

    return 0;

}//end main