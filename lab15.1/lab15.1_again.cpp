#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define MAX_FILE_CONTENT_SIZE 10000 

// ต้นแบบฟังก์ชันอ่านไฟล์
void GetStringFromFile(char fileinfo[], char filename[]); 
// ต้นแบบฟังก์ชันนับคำ
int WordCounter(const char fileinfo[]);

int main() {
    // ประกาศตัวแปรอาร์เรย์สำหรับชื่อไฟล์และเนื้อหาไฟล์
    char filename[MAX_FILENAME_SIZE]; 
    char fileinfo[MAX_FILE_CONTENT_SIZE]; 

    printf("Input\n");
    printf("Enter file name:\n");
    
    // รับชื่อไฟล์จากผู้ใช้
    scanf("%s", filename) ;

    // อ่านเนื้อหาไฟล์
    GetStringFromFile(fileinfo, filename);

    // นำเนื้อหามานับคำ
    int NumberOfWord = WordCounter(fileinfo);
    
    // แสดงผลลัพธ์
    printf("Total number of words in '%s' : ", filename); 
    printf("%d words\n", NumberOfWord); 

    return 0;
}//end main function

void GetStringFromFile(char fileinfo[], char filename[]) {
    FILE *file;
    
    // เปิดไฟล์เพื่ออ่าน
    file = fopen(filename, "r");

    // ตรวจสอบว่าเปิดไฟล์ได้ไหม
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        fileinfo[0] = '\0'; // กำหนดให้เป็นสตริงว่างถ้าเปิดไม่ได้
        return;
    }//end if

    // อ่านข้อมูลจากไฟล์
    if (fgets(fileinfo, MAX_FILE_CONTENT_SIZE, file) == NULL) {
        fileinfo[0] = '\0';
    }//end if

    // ปิดไฟล์
    fclose(file);
}//end GetStringFromFile function

int WordCounter(const char fileinfo[]) {
    int NumberOfWord = 0;
    // inWord = 0: นอกคำ, 1: ในคำ
    int inWord = 0; 

    // วนลูปตรวจสอบทุกตัวอักษรในสตริง
    for (int i = 0; fileinfo[i] != '\0'; i++) {
        
        // เงื่อนไขสำหรับตัวแบ่งคำ: ช่องว่าง หรือ เครื่องหมายวรรคตอน
        if (fileinfo[i] == ' ' || 
            fileinfo[i] == ',' ||
            fileinfo[i] == '.' ||
            fileinfo[i] == '!' ||
            fileinfo[i] == '?' ||
            fileinfo[i] == ':' ||
            fileinfo[i] == ';' ||
            fileinfo[i] == '(' ||
            fileinfo[i] == ')') { 
            
            inWord = 0; // เปลี่ยนสถานะเป็น 'นอกคำ'
        } else {
            // ถ้าเจอตัวอักษรที่ไม่ใช่ตัวแบ่งคำ
            if (inWord == 0) {
                NumberOfWord++; // นับคำใหม่
                inWord = 1;     // เปลี่ยนสถานะเป็น 'ในคำ'
            }//end if
        }//end ifelse
    }//end for

    return NumberOfWord;
}//end WordCounter function