#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("/bin/ls", "", "/", NULL);  // вызываем программу ls
    return 0;
}