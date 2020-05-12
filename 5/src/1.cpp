#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

unsigned long diff(struct timeval t1, struct timeval t2) {
    return t2.tv_sec * 1000000 + t2.tv_usec - t1.tv_sec * 1000000 - t1.tv_usec;
}

int main()
{
    // Структуры хранят время
    struct timeval tv1;
    struct timeval tv2;

    /*Ниже выполняются все команды, на каждой команде засекается время*/

    gettimeofday(&tv1, NULL);
    int fd = creat("1.txt", S_IWUSR);
    gettimeofday(&tv2, NULL);
    printf("Создание файла: %d\n", diff(tv1, tv2));

    gettimeofday(&tv1, NULL);
    for (int i = 0; i < 307200; ++i) {
        write(fd, "0", 1);
    }
    gettimeofday(&tv2, NULL);
    printf("Запись: %d\n", diff(tv1, tv2));

    gettimeofday(&tv1, NULL);
    ftruncate(fd, 0);
    gettimeofday(&tv2, NULL);
    printf("Очистка: %d\n", diff(tv1, tv2));

    gettimeofday(&tv1, NULL);
    close(fd);
    gettimeofday(&tv2, NULL);
    printf("Закрытие: %d\n", diff(tv1, tv2));

    gettimeofday(&tv1, NULL);
    remove("1.txt");
    gettimeofday(&tv2, NULL);
    printf("Удаление: %d\n", diff(tv1, tv2));

    return 0;
}