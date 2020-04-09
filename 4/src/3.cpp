#include <stdio.h>

int main()
{
    int *a = NULL;
    printf("%d", *a); // Ошибка (неопределенное поведение), нельзя разыменовывать указатель на нуль

    return 0;
}