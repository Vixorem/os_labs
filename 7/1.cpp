#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define UPPER 0
#define LOW 1

void change(char* str, int countChange, int typeChange) { 
    while (countChange >= 8) { 
        if (typeChange == UPPER) 
            *((uint64_t *)str) &= 0b1101111111011111110111111101111111011111110111111101111111011111; //обнуляем бит на каждой позиции, кратной 6
        if (typeChange == LOW) 
            *((uint64_t *)str) |= 0b0010000000100000001000000010000000100000001000000010000000100000; //устанавливаем бит на каждой позиции, кратной 6
        countChange -= 8; 
        str += 8;
    }
    while (countChange >= 4) { 
        if (typeChange == UPPER) 
            *((uint32_t *)str) &= 0b11011111110111111101111111011111; 
        if (typeChange == LOW)
            *((uint32_t *)str) |= 0b00100000001000000010000000100000; 
        countChange -= 4; 
        str += 4;
    }

    while (countChange >= 1) { 
        if (typeChange == UPPER) 
            *str &= 0b11011111; 
        if (typeChange == LOW) 
            *str |= 0b00100000; 
        countChange--; 
        str++;
    }
}

void readStr(char* str) {
    unsigned int len = strlen(str); 
    int countUpper = 0;
    int countLow = 0; 
    while (*str != '\0') { 
        if (*str >= 'a' && *str <= 'z') {
            ++countLow; 
            if (countUpper != 0) { 
                change(str-countUpper, countUpper, LOW); 
                countUpper = 0; 
            }
        } else if (*str >= 'A' && *str <= 'Z') {
            ++countUpper; 
            if (countLow != 0) {
                change(str-countLow, countLow, UPPER); 
                countLow = 0; 
            }
        } else {
            countUpper ? change(str-countUpper, countUpper, LOW) : change(str-countLow, countLow, UPPER); 
            countUpper = countLow = 0;
        }

        str++; 
    }
    countUpper ? change(str-countUpper, countUpper, LOW) : change(str - countLow, countLow, UPPER);
    str -= len; 
    
    printf("%s\n", str);
}

int main() {
    char str1[100];
    scanf("%s", str1);
    readStr(str1);
    return 0;
}