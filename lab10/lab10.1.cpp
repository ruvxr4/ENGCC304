#include <stdio.h>   
#include <string.h>  
#include <ctype.h>   


int isPalindrome(char str[]);


int main() {
    char word[100]; 

    
    printf("Enter word:\n"); 
    scanf("%s", word); 

    if (isPalindrome(word)) {
        printf("\nPass.\n");
    } else {
        printf("\nNot Pass.\n");
    }//end if-else

    return 0; 
}//end main fuction

int isPalindrome(char str[]) {
   
    int left = 0; 
    int right = strlen(str) - 1; 

    
    while (left < right) {
        
        if (tolower(str[left]) != tolower(str[right])) {
            
            return 0; 
        }//end if
        
        left++; 
        right--; 
    }//end while

    
    return 1; 
}//end ispalindrome fuction