#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int f = fork(); // создает процесс

    if (!f) {
        f++; 
    } else {
        int a = wait(NULL); // дожидаемся разрешения процесса
        // Возвращает идентификатор дочернего процесса, 
        // который завершил выполнение
    }

    return 0;
}