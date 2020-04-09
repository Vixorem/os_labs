/* Example code for Think OS.

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

int global;

int main ()
{
    int local = 5;
    void *p = malloc(128); // выделяем 128 байт

    // присваеваем одрес нулевого и первого элементов
    int* p1 = (int*)p; 
    int* p2 = ((int*)p) + 1;
    // создаем две переменные на стеке
    int a;
    int b;

    printf("%d %d \n %d %d\n", p1, p2, &a, &b);

    // Проверяем на убывание и возрастание
    if (p1 > p2) {
        printf("В динамической памяти адреса идут в сторону убывания\n");
    } else {
        printf("В динамической памяти адреса идут в сторону возрастания\n");
    }
    if (&a > &b) {
        printf("В стеке адреса идут в сторону убывания\n");
    } else {
        printf("В стеке адреса идут в сторону возрастания\n");
    }

    // printf ("Address of main is %p\n", main);
    // printf ("Address of global is %p\n", &global);
    // printf ("Address of local is %p\n", &local);
    // printf ("Address of p is %p\n", p);
    
    return 0;
} 
