#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void gb(int a){
  printf("Goodbye\n");
}

int main(){

    pid_t cpid; // родительский и дочерний pid
    pid_t ppid;

    signal(SIGUSR1, gb); // сигнал привязывает функцию gb. Если какой то процесс 
                        // отправит SIGUSR1, то вызовется эта функция

    if (!(cpid = fork())) {
        printf("Hello\n");
        ppid = getppid();

        kill(ppid, SIGUSR1); // отправляем из дочернего процесса сигнал
        exit(0);

    } else{
        pause(); // pause ждет, когда отправится сигнал
    }

}