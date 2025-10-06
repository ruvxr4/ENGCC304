#include <stdio.h>

int main() {
    int N;
    int i;
    
    printf("Enter value: ");
    if (scanf("%d", &N) != 1) {
        printf("Output: Invalid input.\n");
        return 1;
    } 

    printf("Output: Series:");
    
    if (N % 2 != 0) {
        for (i = 1; i <= N; i += 2) {
            printf(" %d", i);
        }
    } else {
        for (i = N; i >= 0; i -= 2) {
            printf(" %d", i);
        }
    } // end ifelse

    printf("\n");
    
    return 0;
} // end main