#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 


#define MAX_BOOKS 100

#define MAX_TITLE_LENGTH 100

#define MAX_AUTHOR_LENGTH 100


typedef struct {
    int bookID; // ประกาศ Book ID เป็นจำนวนเต็ม
    char title[MAX_TITLE_LENGTH]; // ประกาศ Title เป็นสตริง
    char author[MAX_AUTHOR_LENGTH]; // ประกาศ Author เป็นสตริง
    int year; // ประกาศ Year เป็นจำนวนเต็ม
} Book;


void addBook(Book books[], int *count); // ฟังก์ชันเพิ่มหนังสือ
void searchBook(Book books[], int count, char title[]); // ฟังก์ชันค้นหาหนังสือ
void displayBooks(Book books[], int count); // ฟังก์ชันแสดงหนังสือทั้งหมด
void displayMenu(); // ฟังก์ชันแสดงเมนู
void clearInputBuffer(); // ฟังก์ชันเคลียร์บัฟเฟอร์อินพุต

int main() {
    Book library[MAX_BOOKS]; // ประกาศอาเรย์โครงสร้างสำหรับเก็บหนังสือ
    int bookCount = 0; // ประกาศและกำหนดค่าเริ่มต้นของตัวนับจำนวนหนังสือ
    int option; // ประกาศตัวแปรสำหรับรับตัวเลือกจากผู้ใช้
    char searchTitle[MAX_TITLE_LENGTH]; // ประกาศสตริงสำหรับเก็บชื่อหนังสือที่ต้องการค้นหา

    library[bookCount].bookID = 101; // กำหนด Book ID เริ่มต้น
    strcpy(library[bookCount].title, "The C Programming Language"); // คัดลอกชื่อหนังสือเริ่มต้น
    strcpy(library[bookCount].author, "Brian W. Kernighan and Dennis M. Ritchie"); // คัดลอกชื่อผู้แต่งเริ่มต้น
    library[bookCount].year = 1978; // กำหนดปีที่พิมพ์เริ่มต้น
    bookCount++; // เพิ่มจำนวนหนังสือที่บันทึกไว้ 1

    do { // เริ่มต้น do-while loop
        displayMenu(); // เรียกใช้ฟังก์ชันแสดงเมนู
        printf("Choose an option: "); // แสดงข้อความให้ผู้ใช้เลือกตัวเลือก
        if (scanf("%d", &option) != 1) { // รับตัวเลือกและตรวจสอบความถูกต้องของอินพุต
            clearInputBuffer(); // เคลียร์บัฟเฟอร์หากอินพุตไม่ถูกต้อง
            option = -1; // กำหนดค่า option เป็น -1 เพื่อเข้า default
        } // end if
        clearInputBuffer(); // เคลียร์บัฟเฟอร์หลังรับตัวเลข

        switch (option) { // เริ่มต้น switch case
            case 1: // หากเลือก 1 (เพิ่มหนังสือ)
                addBook(library, &bookCount); // เรียกใช้ฟังก์ชันเพิ่มหนังสือ
                break; // ออกจาก switch
            case 2: // หากเลือก 2 (ค้นหาหนังสือ)
                printf("Enter Title to Search: "); // แสดงข้อความให้กรอกชื่อหนังสือ
                if (fgets(searchTitle, MAX_TITLE_LENGTH, stdin) != NULL) { // รับชื่อหนังสือ (รวมช่องว่าง)
                    searchTitle[strcspn(searchTitle, "\n")] = 0; // ลบอักขระขึ้นบรรทัดใหม่
                } // end if
                searchBook(library, bookCount, searchTitle); // เรียกใช้ฟังก์ชันค้นหาหนังสือ
                break; // ออกจาก switch
            case 3: // หากเลือก 3 (แสดงหนังสือทั้งหมด)
                displayBooks(library, bookCount); // เรียกใช้ฟังก์ชันแสดงหนังสือทั้งหมด
                break; // ออกจาก switch
            case 4: // หากเลือก 4 (ออกจากโปรแกรม)
                printf("Exiting program. Goodbye!\n"); // แสดงข้อความออกจากโปรแกรม
                break; // ออกจาก switch
            default: // กรณีที่เลือกตัวเลือกอื่นที่ไม่ถูกต้อง
                printf("Invalid option. Please try again.\n"); // แสดงข้อความตัวเลือกไม่ถูกต้อง
        } // end switch
        printf("\n"); // ขึ้นบรรทัดใหม่
    } while (option != 4); // วนซ้ำ do-while loop ตราบเท่าที่ตัวเลือกไม่เป็น 4

    return 0; // คืนค่า 0 เมื่อโปรแกรมจบการทำงาน
} // end main

void displayMenu() { // ฟังก์ชันแสดงเมนู
    printf("--- Library Management System ---\n"); // แสดงหัวข้อ
    printf("1. Add new Book\n"); // แสดงตัวเลือก 1
    printf("2. Search Book by Title\n"); // แสดงตัวเลือก 2
    printf("3. Display All Books\n"); // แสดงตัวเลือก 3
    printf("4. Exit Program\n"); // แสดงตัวเลือก 4
    printf("---------------------------------\n"); // แสดงเส้นแบ่ง
} // end displayMenu function

void clearInputBuffer() { // ฟังก์ชันเคลียร์บัฟเฟอร์
    int c; // ประกาศตัวแปรรับอักขระ
    while ((c = getchar()) != '\n' && c != EOF); // วนอ่านอักขระจนกว่าจะเจอ Newline หรือ EOF
} // end clearInputBuffer function

void addBook(Book books[], int *count) { // ฟังก์ชันเพิ่มหนังสือ
    if (*count >= MAX_BOOKS) { // ตรวจสอบว่าจำนวนหนังสือเกินขีดจำกัดหรือไม่
        printf("Error: The library is full. Cannot add more books.\n"); // แสดงข้อความเต็ม
        return; // จบฟังก์ชัน
    } // end if

    printf("Enter Book ID: "); // แสดงข้อความให้กรอก Book ID
    if (scanf("%d", &books[*count].bookID) != 1) { // รับ Book ID และตรวจสอบความถูกต้อง
        printf("Invalid input for Book ID.\n"); // แสดงข้อความอินพุตไม่ถูกต้อง
        clearInputBuffer(); // เคลียร์บัฟเฟอร์
        return; // จบฟังก์ชัน
    } // end if
    clearInputBuffer(); // เคลียร์บัฟเฟอร์หลังรับตัวเลข

    printf("Enter Title: "); // แสดงข้อความให้กรอก Title
    if (fgets(books[*count].title, MAX_TITLE_LENGTH, stdin) != NULL) { // รับ Title
        books[*count].title[strcspn(books[*count].title, "\n")] = 0; // ลบอักขระขึ้นบรรทัดใหม่
    } // end if

    printf("Enter Author: "); // แสดงข้อความให้กรอก Author
    if (fgets(books[*count].author, MAX_AUTHOR_LENGTH, stdin) != NULL) { // รับ Author
        books[*count].author[strcspn(books[*count].author, "\n")] = 0; // ลบอักขระขึ้นบรรทัดใหม่
    } // end if
    
    printf("Enter Year: "); // แสดงข้อความให้กรอก Year
    if (scanf("%d", &books[*count].year) != 1) { // รับ Year และตรวจสอบความถูกต้อง
        printf("Invalid input for Year.\n"); // แสดงข้อความอินพุตไม่ถูกต้อง
        clearInputBuffer(); // เคลียร์บัฟเฟอร์
        return; // จบฟังก์ชัน
    } // end if
    clearInputBuffer(); // เคลียร์บัฟเฟอร์หลังรับตัวเลข

    (*count)++; // เพิ่มจำนวนหนังสือที่บันทึกไว้
    printf("Book added successfully!\n"); // แสดงข้อความเพิ่มสำเร็จ
} // end addBook function

void searchBook(Book books[], int count, char title[]) { // ฟังก์ชันค้นหาหนังสือ
    int i; // ประกาศตัวแปรสำหรับลูป
    int found = 0; // ประกาศและกำหนดค่าเริ่มต้นตัวแปรสถานะการค้นหา

    for (i = 0; i < count; i++) { // เริ่มต้น for loop วนตามจำนวนหนังสือทั้งหมด
        if (strcmp(books[i].title, title) == 0) { // เปรียบเทียบชื่อหนังสือ
            printf("Book ID: %d\n", books[i].bookID); // แสดง Book ID
            printf("Title: %s\n", books[i].title); // แสดง Title
            printf("Author: %s\n", books[i].author); // แสดง Author
            printf("Year: %d\n", books[i].year); // แสดง Year
            found = 1; // ตั้งค่าสถานะว่าพบหนังสือ
            break; // ออกจาก loop ทันทีที่พบ
        } // end if
    } // end for

    if (!found) { // ตรวจสอบว่าไม่พบหนังสือ
        printf("Book not found.\n"); // แสดงข้อความไม่พบหนังสือ
    } // end if
} // end searchBook function

void displayBooks(Book books[], int count) { // ฟังก์ชันแสดงหนังสือทั้งหมด
    if (count == 0) { // ตรวจสอบว่ามีหนังสือในระบบหรือไม่
        printf("The library is empty. No books to display.\n"); // แสดงข้อความไม่มีหนังสือ
        return; // จบฟังก์ชัน
    } // end if
    
    printf("--- All Books in Library (%d books) ---\n", count); // แสดงหัวข้อและจำนวนหนังสือ
    for (int i = 0; i < count; i++) { // เริ่มต้น for loop วนตามจำนวนหนังสือทั้งหมด
        printf("Book #%d:\n", i + 1); // แสดงลำดับที่ของหนังสือ
        printf("  Book ID: %d\n", books[i].bookID); // แสดง Book ID
        printf("  Title: %s\n", books[i].title); // แสดง Title
        printf("  Author: %s\n", books[i].author); // แสดง Author
        printf("  Year: %d\n", books[i].year); // แสดง Year
        printf("---------------------------------\n"); // แสดงเส้นแบ่งรายการ
    } // end for
} // end displayBooks function