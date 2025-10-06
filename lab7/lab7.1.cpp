#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rnumber, gnumber;
    int play = 0;
    
    srand(time(NULL)); 

    do {
        printf("Do u want to play game?(1=play, -1=exit): ");
        if (scanf("%d", &play) != 1 || (play != 1 && play != -1)) {
            printf("Invalid selection. Please try again.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (play == 1) {
            int score = 100;
            rnumber = rand() % 100 + 1;
            
            printf("\n--- Game Started! ---\n");
            
            do {
                printf("Score: %d\n", score);
                printf("Input ur guess number (1-100): ");
                
                if (scanf("%d", &gnumber) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                if (gnumber == rnumber) {
                    printf("\n🎉 CORRECT! 🎉\n");
                    printf("Final Score: %d\n", score);
                    break;
                } else {
                    score -= 10;
                    
                    if (score <= 0) {
                        printf("\n❌ WRONG! Game Over. The number was %d.\n", rnumber);
                        printf("Final Score: 0\n");
                        break;
                    } // end if
                    
                    if (gnumber > rnumber) {
                        printf("Too high. Try a smaller number. (Score: %d)\n", score);
                    } else {
                        printf("Too low. Try a bigger number. (Score: %d)\n", score);
                    } // end ifelse
                } // end ifelse

            } while (1); // end dowhile
            
            printf("--- Game Over ---\n");

        } // end if
    } while (play != -1); // end dowhile

    printf("See u again!\n");
    return 0;
} // end main