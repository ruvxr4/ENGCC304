#include <stdio.h>

int main(){
    int a=0;
    printf("enter value:");
    scanf("%d", &a);

    for(&a; a>=0; a -= 2){
        if(a%2 == 0){
            printf("%d ", a);
        }
    }
}