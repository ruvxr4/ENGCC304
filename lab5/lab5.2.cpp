#include <stdio.h>
int main(){

    int score = 0 ,input_status;

    printf("please enter ur score: ");

    input_status = scanf("%d", &score);

    if(input_status != 1){
        printf("error! u entered non-numeric characters.\n");
        printf("please run the program again.\n");
        return 1;
    }

    printf("grade : ");


    if(score < 0 || score > 100){
        printf("ERROR! Invalid Score. Score must be between 0 and 100.");
    } 
    else if(score >=80){
        printf("A!");
    }else if(score >=75 && score <80){
        printf("B+!");
    }else if(score >=70 && score <75){
        printf("B!");
    }else if(score >=65 && score <70){
        printf("C+!");
    }else if(score >=60 && score <65){
        printf("C!");
    }else if(score >=55 && score <60){
        printf("D+!");
    }else if(score >=50 && score <55){
        printf("D!");
    }else {
        printf("F");
    } //end if
    return 0 ;

    
    
}