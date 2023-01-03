#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>


int main(){
    int pid, pid1, pid2, status, x;
    srand(time(NULL));
    pid1 = fork();
    if(pid1==0){
        printf("1) sono il primo processo figlio con pid: %i \n", getpid());
        sleep(4);
        exit(1);
    }else{
        pid2 = fork();
        if(pid2==0){
            printf("2) sono il primo processo figlio con pid: %i \n", getpid());
            sleep(1);
            exit(2);
        }else{
            printf("3) Sono in attesa del figlio più lento \n");
            pid = waitpid(pid1, &status, 0);
            printf("4) finamente termina il figlio con pid: %d\n ", pid);
            return 0;
        }
    }
}
