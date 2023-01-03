#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(){
    int status;
    int pid = fork();
    if (pid == 0){
        printf("Sono il figlio il mio pid e': %d.", getpid());
        printf("il mio papi ha pid: %d\n.", getppid());
        exit(69);
    }else{
        printf("sono il papi il mio pid e': %d.", getpid());
        printf("L'exit di mio figlio (%d) e': %d\n.", wait(&status), status);
        return 0;
    }
}
