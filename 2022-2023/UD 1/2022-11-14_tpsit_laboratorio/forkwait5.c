#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#define NRFIGLI 4

int main(){
    int status, pid, x;
    for(x=0; x<NRFIGLI; x++){
        pid = fork();
        if(pid == 0){
            printf("Sono il figlio il mio pid e': %d.", getpid());
            printf("il mio papi ha pid: %d\n.", getppid());
            exit(0);
        }else{
            printf("sono il papi il mio pid e': %d.", getpid());
            printf("Il pid del mio figlio corrente e':%d \n ", pid);
            printf("L'exit di mio figlio (%d) e': %d\n\n.", status);
            
        }
    }
    return 0;
}
