#include <stdio.h> 


int isPrime(int num);

int main() {
    int n; 
    printf("Enter N :\n");
    scanf("%d", &n); 

    int values[n]; 

    
    for (int i = 0; i < n; i++) { 
        printf("Enter value[%d] :\n", i); 
        scanf("%d", &values[i]); 
    }//end for

    printf("\n"); 
    printf("Index: "); 
    for (int i = 0; i < n; i++) { 
        printf("%3d", i); 
    }//end for
    printf("\n"); 
    printf("Array: "); 
    for (int i = 0; i < n; i++) { 
        if (isPrime(values[i])) { 
            printf("%3d", values[i]); 
        } else {
            printf("%3s", "#"); 
        }//end if-else
    }//end for
    printf("\n"); 

    return 0; 
}//end main

int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    }//end if

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) { 
            return 0; 
        }//end if
    }//end for

    
    return 1; 
}//end isprime fuction