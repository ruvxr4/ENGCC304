#include <stdio.h>
#include <string.h>

struct Student {
    char Name[50];
    char ID[5];
    float ScoreSub1;
    float ScoreSub2;
    float ScoreSub3;
    float ScoreSub4;
    float ScoreSub5;
} typedef S;

void Grade(float score) {
    if (score >= 80) {
        printf("A ");
    } else if (score >= 75) {
        printf("B+ ");
    } else if (score >= 70) {
        printf("B ");
    } else if (score >= 65) {
        printf("C+ ");
    } else if (score >= 60) {
        printf("C ");
    } else if (score >= 55) {
        printf("D+ ");
    } else if (score >= 50) {
        printf("D ");
    } else {
        printf("F ");
    } // end if-else
} // end function printGrade

int main() {
    int n = 3;
    S input[n]; 

    printf("Enter the details of %d students :\n", n);

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        
        printf("Name: \n");
        scanf(" %[^\n]", input[i].Name); 

        printf("ID: \n");
        scanf("%s", input[i].ID);

        printf("Scores in Subject 1: \n");
        scanf("%f", &input[i].ScoreSub1);

        printf("Scores in Subject 2: \n");
        scanf("%f", &input[i].ScoreSub2);

        printf("Scores in Subject 3: \n");
        scanf("%f", &input[i].ScoreSub3);

        printf("Scores in Subject 4: \n");
        scanf("%f", &input[i].ScoreSub4);

        printf("Scores in Subject 5: \n");
        scanf("%f", &input[i].ScoreSub5);
        printf("\n");
    } // end for

    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", input[i].Name);
        printf("ID: %s\n", input[i].ID);
        
        printf("Scores: %.0f %.0f %.0f %.0f %.0f\n", 
               input[i].ScoreSub1, 
               input[i].ScoreSub2, 
               input[i].ScoreSub3, 
               input[i].ScoreSub4, 
               input[i].ScoreSub5);

        printf("Grades: ");
        Grade(input[i].ScoreSub1);
        Grade(input[i].ScoreSub2);
        Grade(input[i].ScoreSub3);
        Grade(input[i].ScoreSub4);
        Grade(input[i].ScoreSub5);
        printf("\n"); 

        
        float average = (input[i].ScoreSub1 + input[i].ScoreSub2 + input[i].ScoreSub3 + input[i].ScoreSub4 + input[i].ScoreSub5) / 5.0;
        printf("Average Scores: %.1f\n\n", average);
    } // end for

    return 0;
} // end function main