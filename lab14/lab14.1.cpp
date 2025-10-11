#include <stdio.h> // สำหรับ I/O
#include <limits.h> // สำหรับ INT_MAX, INT_MIN

#define MAX_SIZE 100 // ขนาดสูงสุดของอาเรย์

// หาค่าที่น้อยที่สุดในอาเรย์
int findMin(int arr[], int size) {
    if (size <= 0) {
        return INT_MAX;
    } // end if
    int min = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } // end if
    } // end for
    return min;
} // end findMin_function

// หาค่าที่มากที่สุดในอาเรย์
int findMax(int arr[], int size) {
    if (size <= 0) {
        return INT_MIN;
    } // end if
    int max = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } // end if
    } // end for
    return max;
} // end findMax_function

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int input_val;
    int status;
    int i;

    // รับค่าจากผู้ใช้
    printf("Enter value (Press any non-integer key e.g., 'q' to stop input): \n");
    while (size < MAX_SIZE) {
        status = scanf("%d", &input_val); 

        if (status == 1) { 
            arr[size] = input_val;
            size++;
        } else {
            // หยุดการรับค่า
            break; 
        } // end if else
    } // end while
    
    // เคลียร์ buffer
    while(getchar() != '\n'); // end while 

    if (size == 0) {
        printf("No data entered. Program terminated.\n");
        return 1;
    } // end if
    
    // แสดง Index และ Array
    printf("\nOutput:\n");
    printf("Index: ");
    for (i = 0; i < size; i++) {
        printf("%d ", i);
    } // end for
    printf("\n");

    printf("Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    } // end for
    printf("\n");
    
    // ค้นหาและแสดงค่า Min/Max
    int min_val = findMin(arr, size);
    int max_val = findMax(arr, size);

    printf("Min : %d\n", min_val);
    printf("Max : %d\n", max_val);

    return 0;
} // end main