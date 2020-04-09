#include <stdio.h>
#include <unistd.h>

int main()
{
    //todo
    execl("/bin/ls", "ls", "-l", ".", NULL);  // вызываем программу ls 
    return 0;
}