#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void pr(int a){
  printf("HELLO\n");
}

int main(){

    pid_t cpid;
    pid_t ppid;

    signal(SIGUSR1, pr); // связываем сигнал с вызовом функции

    if (!(cpid = fork())) {
        close(STDOUT_FILENO); // закрываем поток в дочернем процессе
        printf("HELLO\n");  // не получается напечатать
        kill(ppid, SIGUSR1);
        exit(0);

    } else{
        pause(); // но в этом процессе получится напечатать
    }

}