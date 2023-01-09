#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    int pid;
    printf("1) prima della fork \n");
    pid = fork();
    printf("2) dopo della fork \n");
    if(pid == 0){
        printf("3) sono il processo figlio con pid %d ", getpid());
        sleep(3);
        printf("Il mio papi ha il pid  %d\n", getppid());
        exit(1);
    }
    else{
        printf("3) sono il processo padre con pid %d", getpid());
        printf("il mio papi ha pid %d\n", getppid());
        exit(0);
    }
}
