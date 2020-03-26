#include <cstdlib>

int main()
{
    char *a = (char *) malloc(1000000000);

    for (int i = 0; i <= 1000000000; i = (i + 1) % 1000000000)
     {
         ++a[i];
     }
     
    return 0;
}