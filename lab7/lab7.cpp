#include <stdio.h>
#include <stdlib.h>

int main(){
int rnumber, gnumber ;
int play = 0;
int score = 100;

do{
    do{
    printf("Do u want to play game?(1=play,-1=exit)") ;
    scanf("%d", &play) ;
    if(play == 1){
            printf("ur score=100/n");
            rnumber = rand() % 100 +1 ;
            printf("input ur guess number");
            scanf("%d", &gnumber);
        if(gnumber == rnumber){
            printf("correct!\n");
            printf("score:  %d\n", score);
            break; //ออกloop
    } else {
        score -= 10;
        if(score == 0){
            printf("wrong! ur score is 0. game over.\n");
            break ;
        }
        if(gnumber > rnumber){
            printf("i think it's too high.try a smaller number.\n");
        
        }else{
            printf("i think it's too low.try a bigger number.\n");
        }
        printf("score: %d\n", score);
    }


}
    
    }while(score > 0);

    }while(play != -1);

    printf("see u again\n");
    return 0;

    
}


