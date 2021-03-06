#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stat stat_t;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        return 1;
    }

    int linesNum = atoi(argv[1]);
    char* fileName = argv[2];
    int fd = open(fileName, S_IREAD|S_IWRITE);
    stat_t fs;
    stat(fileName, &fs);
    int fsize = fs.st_size;
    char* buff = (char*)malloc(fsize);
    int lineCnt = 0;
    int byteCnt = 0;
    /*идев в конец файла, и с помоюсь lseek перемещаем его ближе к началу, 
    тем самым читаю задом наперед*/
    for (int i = 0; i < fsize; ++i) {
        lseek(fd, -i, SEEK_END);
        char c;
        read(fd, &c, 1);
        if (c == '\n') {
            ++lineCnt;
            if (lineCnt >= linesNum) {
                break;
            }
        }
        buff[i] = c;
        ++byteCnt;
    }
    // печатаем то, что сохранили
    for (int i = byteCnt - 1; i >= 0; --i) {
        printf("%c", buff[i]);
    }

    close(fd);
    free(buff);

    return 0;
}