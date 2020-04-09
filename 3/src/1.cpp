#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *a = (char *) malloc(1000000000);

    printf("%d\n", getpid());
    for (int i = 0; i <= 1000000000; i = (i + 1) % 1000000000)
     {
         ++a[i];
     }
     
    return 0;
}