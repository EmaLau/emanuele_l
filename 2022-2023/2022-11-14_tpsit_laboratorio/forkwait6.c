#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>


int main(){
    int pid, status;
    pid = fork();
    if(pid == 0){
        printf("eseguito dal figlio \n");
        exit(0);
    }else{
        pid = wait(&status);
        if(WIFEXITED(status)){
            printf("Term. volontaria %d con stato %d\n", pid, WEXITSTATUS(status));
        }else{
            if(WIFSIGNALED(status)){
                printf("terminazione volontaria per segnale %d", WTERMSIG(status));
            }
        }
    }
}
