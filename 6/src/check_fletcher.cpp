#include <stdio.h>
#include <sys/time.h>

unsigned long diff(struct timeval t1, struct timeval t2) {
    return t2.tv_sec * 1000000 + t2.tv_usec - t1.tv_sec * 1000000 - t1.tv_usec;
}

struct timeval tv1;
struct timeval tv2;

// алгоритм флетчера
void check_fletcher(char *fileName, int expectedSum) {
    unsigned int sum1 = 0; 
    unsigned int sum2 = 0;
    char buff; 

    struct timeval tv1;
    struct timeval tv2; 

    FILE *file = fopen(fileName, "r"); 

    // считываем и вычисляем сумму
    while (fread(&buff, 1, 1, file) != 0) { 
        sum1 = (sum1 + buff) % 255;
        sum2 = (sum2 + sum1) % 255; 
    }

    unsigned int newSum = (sum2 << 8) | sum1; 


    fclose(file); 
    printf("Ожидаемая сумма %d\n", expectedSum);
    printf("Полученная сумма %d\n", newSum);
}

int main() {
    gettimeofday(&tv1, NULL);
    check_fletcher("../tests/1.txt", 27662);
    gettimeofday(&tv2, NULL);
    printf("Веремя: %d\n", diff(tv1, tv2));
    gettimeofday(&tv1, NULL);
    check_fletcher("../tests/2.txt", 13313); 
    gettimeofday(&tv2, NULL);
    printf("Веремя: %d\n", diff(tv1, tv2));

    return 0;
}