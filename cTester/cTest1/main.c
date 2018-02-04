#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>


//    unsigned char a = 97;
//    unsigned char b = 0x97;
//    unsigned char c[] = "10010010";
//    printDecimal(c);printf("\n");
//    printBinary(b);printf("\n");

//    unsigned char c = 128;
//    printBinary(c); printf("\n");
//    c |= (1<<1 | 1<<3 | 1<<5);
//    printBinary(c); printf("\n");
//    printf("%d\n",c);



void clearScreen(void) {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}


void printDecimal(char string[]) {
//    char str[] = "11111110";
//    printDecimal(str);
    int sum = 0;
    for (int i = 0; i < 8; i++){
        if (string[7-i] == '1'){
            sum += pow(2,i);
        }
    }
    printf("%i", sum);
}

void printBinary(unsigned short byte ) {
    /*
     * unsigned char byte = 255;
     * test2(byte);
     */
    for (int i = 15; i >= 0; i--) {
        int bit = (byte >> i) & 1;
        printf("%d", bit);
    }
}

void space(int u){
    int a = u;
    for (int i = a; i > 0; i--) {
        printf(" ");
    }
}

void pattern(void){
    unsigned short c = 0x0000;
    while (1) {
        unsigned short a = 0x8000;
        unsigned short b = 0x0001;
        for (int i = 0; i < 15; i++){
            a >>= 1;
            b <<= 1;
            if (c) {
                space(15-i);
            } else {
                space(i);
            }
            printBinary(a|b);
            clearScreen();
            Sleep(250);
            
        }
        c ^= 0x0001;
    }
}

void test1(void){
    int i = strlen("Hello World");
    printf("%i", i);
}


int main(int argc, char **argv)
{
    pattern();
    return 1;
}