#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void gestore(int signum){
    printf("-> il processo %d sente il segnale %d\n", getpid(), signum);
}

int main(int argc, const char * argv[]) {
    int i;
    printf("Il processo padre ha PID %d e PGID %d \n", getpid(), getpgid(0));
    signal(SIGINT, gestore);
    if(fork() == 0)
        setpgid(0, getpid());
    printf("Il processo PID %d PGID %d aspetta .. \n ", getpid(), getpgid(0));
    for(i=1; i<=3; i++){
        printf("Il processo %d è vivo \n", getpid());
        sleep(2);
    }
    return 0;
}

