#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    // каналы для записи и чтения для двух процессов
    int p1[2]; 
    int p2[2];
    char a1[100] = {0};
    char a2[100] = {0};
    pipe(p1);
    pipe(p2);

    int f = fork();
    if (!f) {
        char s[] = {"12345"};  // в дочернем классе пишим первый кусок строки
        close(p1[0]);
        write(STDIN_FILENO, s, strlen(s)); // записываем его
        close(p1[1]);
        int f1 = fork(); 
        if (!f1) {
            char s2[] = {"67890"}; // в этом процессе дописываем строку
            close(p2[0]);
            write(STDIN_FILENO, s2, strlen(s2));
           // write(STDIN_FILENO, '\0', 1);
            close(p2[1]);
        }
        
    } else {
        close(p1[1]);
        close(p2[1]);
        read(p1[0], a1, 5);
        read(p2[0], a2, 5);
        printf("%s%s", a1, a2);
        // в главном процесссе считали все и вывели
    }

    return 0;
}