#include <stdio.h>
#include <sys/time.h>

unsigned long diff(struct timeval t1, struct timeval t2) {
    return t2.tv_sec * 1000000 + t2.tv_usec - t1.tv_sec * 1000000 - t1.tv_usec;
}

// переменные для замера времени
struct timeval tv1;
struct timeval tv2;

// проверка суммы
void check_xor(char *fileName, int expectedSum) {
    unsigned char sum = 0; 
    char buff; 
    FILE *file = fopen(fileName, "r");

    // читаем из файла и вычисляем сумму
    while (fread(&buff, 1, 1, file) != 0) { 
        sum ^= buff;
    }

    fclose(file);
    // показываем полученную сумму и ожидаемую
    printf("Ожидаемая сумма %d\n", expectedSum);
    printf("Полученная сумма %d\n", sum);
}

int main() {
    gettimeofday(&tv1, NULL);
    check_xor("../tests/1.txt", 96);
    gettimeofday(&tv2, NULL);
    printf("Веремя: %d\n", diff(tv1, tv2));
    gettimeofday(&tv1, NULL);
    check_xor("../tests/2.txt", 25); 
    gettimeofday(&tv2, NULL);
    printf("Время: %d\n", diff(tv1, tv2));

    return 0;
}