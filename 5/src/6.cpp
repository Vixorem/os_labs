#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printOffset(int offset) {
    for (int i = 0; i < offset; ++i) {
        printf(" ");
    }
}

void dirTree(char * dir_name, int offset) {
    struct dirent *dt;
    struct stat st;
    DIR *dir = opendir(dir_name); // открыли директорию

    if (dir == NULL) {
        printf("Error");
        exit(1);
    } // проверка на оши#include <stdio.h>
#include <zconf.h>
#include <sys/time.h>

unsigned long get_time_difference(int t1_sec, int t1_usec, int t2_sec, int t2_usec) { //функция для рассчета времени
    return t2_sec*1000000 + t2_usec - t1_sec*1000000 - t1_usec;
}

void check_xor(char *fileName, int expectedRes) {
    unsigned char checkXor = 0; //начальное значение чек суммы
    char buff; //буфер для считывания

    struct timeval tv1; //для записи времени
    struct timeval tv2; //для записи времени

    FILE *file = fopen(fileName, "r"); //открываем файл
    if (file == NULL) { //проверяем успешность открытия
        exit(1);
    }

    gettimeofday(&tv1, NULL); //замеряем время перед началом

    while (fread(&buff, 1, 1, file) != 0) { //пока не считали весь файл читаем по байту и считаем чексумму
        checkXor ^= buff;
    }

    gettimeofday(&tv2, NULL); //замеряем время после окончания

    fclose(file); //закрываем файл

    printf("Result checksum %d, expected result %d\n", checkXor, expectedRes); //выводим полученную и ожидаемую чексумму
    printf("Time %ld мс\n", get_time_difference(tv1.tv_sec, tv1.tv_usec, tv2.tv_sec, tv2.tv_usec)); // выводим время
}

int main() {
    check_xor("../tests/test1.txt", 113); //Тест 1
    check_xor("../tests/test2.txt", 47); //Тест 2
    check_xor("../tests/test3.txt", 77); //Тест 3
    check_xor("../tests/test4.txt", 117); //Тест 4
    return 0;
}бку

    while ((dt = readdir(dir)) != NULL) { // бежим по всем дирректориям
        if (strcmp(dt->d_name, ".") != 0 && strcmp(dt->d_name, "..") != 0) {
            printOffset(offset); //выводим смещение
            printf("%s\n", dt->d_name); // выводим название файла или дирректории
            stat(dt->d_name, &st); //получаем данные о файле или дирректории
            if (dt->d_type == DT_DIR) { //если дирректория, то заходим в неё
                char path[2048];
                snprintf(path, sizeof path, "%s/%s", dir_name, dt->d_name); //склеиваем путь
                dirTree(path, offset + 2); //рекурсивно заходим в дирреткорию
            }
        }
    }
    
    closedir(dir); // закрываем дирректорию
}

void dirTreeSearch(char * dir_name, char * search_dir_name, int depth) {
    char path[2048];
    struct dirent *dt;
    struct stat st;
    DIR *dir = opendir(dir_name); // открыли директорию
    depth--; //уменьшили глубину

    if (dir == NULL) {
        printf("Error");
        exit(1);
    } // проверка на ошибку

    while ((dt = readdir(dir)) != NULL) { //бежим по дирректориям
        snprintf(path, sizeof path, "%s/%s", dir_name, dt->d_name); //склеиваем путь
        if (strcmp(dt->d_name, search_dir_name) == 0 && dt->d_type == DT_DIR) {
            dirTree(path, 0);
        } //если нашли нужную дирректорию, то вызываем печать дерева
        if (dt->d_type == DT_DIR && strcmp(dt->d_name, ".") != 0 && strcmp(dt->d_name, "..") != 0 && depth > 0) {
            dirTreeSearch(path, search_dir_name, depth);
        } //продолжаем поиск в каждой дирректории
    }




}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        dirTree(".", 0);
    } // первый вариант
    if (argc == 2) {
        dirTreeSearch(".", argv[1], __INT32_MAX__);
    } // второй вариант
    if (argc == 4 && strcmp(argv[1], "-d") == 0 && atoi(argv[3]) > 0) {
        dirTreeSearch(".", argv[2], atoi(argv[3]));
    } // третий вариант
    return 0;
}