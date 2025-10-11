#include <stdio.h>

#define SIZE 7

int main() {
    int series[] = { 15, 7, 25, 3, 73, 32, 45 };
    int i, j, min_idx, temp;
    int target_value = 32;
    int target_pos = -1;

    printf("Old Series : ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", series[i]);
        if (i < SIZE - 1) {
            printf(", ");
        } //end if
    } //end for
    printf("\n");

    for (i = 0; i < SIZE - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < SIZE; j++) {
            if (series[j] < series[min_idx]) {
                min_idx = j;
            } //end if
        } //end for
        
        if (min_idx != i) {
            temp = series[i];
            series[i] = series[min_idx];
            series[min_idx] = temp;
        } //end if
    } //end for

    printf("New Series : ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", series[i]);
        if (series[i] == target_value) {
            target_pos = i + 1; 
        } //end if
        if (i < SIZE - 1) {
            printf(", ");
        } //end if
    } //end for
    printf("\n");

    if (target_pos != -1) {
        printf("Pos of %d : %d\n", target_value, target_pos);
    } else {
        printf("Pos of %d : Not Found\n", target_value);
    } //end ifelse
    
    return 0;
} //end main
