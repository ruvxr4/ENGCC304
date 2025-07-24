#include <stdio.h>
int main(){
    char id[11];
    int hrs ;
    float r, s ;

printf("input the employees ID(Max. 10 chars):");
scanf("%s", id);
printf("input the working hrs:");
scanf("%d", &hrs);
printf("salary amount/hr:") ;
scanf("%f", &r) ;

s = hrs * r ;

printf("\nexpected output:\n");
printf("employees ID = %s\n", id);
printf("salary = U$ %.2f\n", s);

return 0;
}

