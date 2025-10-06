#include <stdio.h>
#include <string.h>

const char *words_up_to_19[] = {
    "zero", "one", "two", "Three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen"
};

int main() {
    int input_number;
    int array_size = 20;
    int found = 0;

    printf("Enter Number (0-19): ");
    if (scanf("%d", &input_number) != 1) {
        printf("Result : Invalid input.\n");
        return 1;
    } // end if

    printf("User Input :%d\n", input_number);

    for (int i = 0; i < array_size; i++) {
        if (i == input_number) {
            if (input_number == 3) {
                printf("Result : Three\n");
            } else {
                printf("Result : %s\n", words_up_to_19[i]);
            } // end ifelse
            
            found = 1;
            break; 
        } // end if
    } // end for
    
    if (found == 0) {
        printf("Result : Number out of defined range (0-19).\n");
    } // end if

    return 0;
} // end main