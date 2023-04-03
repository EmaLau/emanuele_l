#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int pid, pid1, pid2;
    pid1 = fork();
    if(pid1 == 0){
        printf("1) sono il primo processo figlio con pid %i\n ", getpid());
        exit(1);
    }else{
        printf("2) sono il processo padre \n");
        printf("3) ho creato un processo con pid: %i\n", pid1);
        printf("4) il mio pid e' invece: %i\n", getpid());
        pid2=fork();
        if(pid2==0){
            printf("5) sono il secondo processo figlio con pid: %i\n", getpid());
            exit(2);
        }else{
            printf("6) sono il processo padre\n");
            printf("7) ho creato un secondo processo con pid: %i\n", pid2);
        }
    }
}
