#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int f = fork(); // создает процесс

    if (!f) {
        f++; 
        printf("hello\n");
    } else {
        int a = wait(NULL); // дожидаемся завершения процесса
        // Возвращает идентификатор дочернего процесса, 
        // который завершил выполнение
        printf("goodbye");
    }

    return 0;
}