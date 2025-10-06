#include <stdio.h>

int main(){

    int D, Sec, SecPerDay;
    
    SecPerDay = 86400 ;

    printf("input days : ");

    scanf("%d",&D);

    Sec = D * SecPerDay ;

    printf("%d Days = %d second",D, Sec);

    return 0;

}