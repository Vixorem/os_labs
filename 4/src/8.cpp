#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *data = (int*)malloc(100);
    data[1] = 87;
    free(data);
    printf("%d\n", data[1]);
    return 0;
}