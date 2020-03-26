#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <memory.h>

int main() 
{
    int x = 100;
    
    printf("Before: %d\n", x);
    int f = fork(); // создаем новый процесс

    if (f) { // дочерний процесс будет 0, родительский - не ноль
        x += 15;
        printf(">> %d\n", x);
    } else {
        x += 54;
        printf(">> %d\n", x);
    }
    
    return 0;
}
