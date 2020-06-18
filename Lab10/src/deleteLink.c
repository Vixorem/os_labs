#include <stdio.h>
#include <unistd.h>

int main() {
    if (unlink("test.txt") == -1) { //удаляем ссылку и проверяем на ошибку
        printf("Error");
        return 1;
    }
    return 0;
}