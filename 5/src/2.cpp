#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

// вычисляет разницу во времени
unsigned long diff(struct timeval t1, struct timeval t2) {
    return t2.tv_sec * 1000000 + t2.tv_usec - t1.tv_sec * 1000000 - t1.tv_usec;
}

int main()
{
    // переменные для хранения времени
    struct timeval tv1;
    struct timeval tv2;

    // проделываем все операции, засекая время
    gettimeofday(&tv1, NULL);
    int fd = creat("1.txt", S_IWUSR);
    for (int i = 0; i < 307200; ++i) {
        write(fd, "0", 1);
    }
    close(fd);
    remove("1.txt");
    gettimeofday(&tv2, NULL);
    printf("POSIX: %d\n", diff(tv1, tv2));

    gettimeofday(&tv1, NULL);
    FILE* f = fopen("1.txt", "w");
    for (int i = 0; i < 307200; ++i) {
        fwrite("0", 1, 1, f);
    }
    fclose(f);
    remove("1.txt");
    gettimeofday(&tv2, NULL);
    printf("stdio: %d\n", diff(tv1, tv2));

    return 0;
}