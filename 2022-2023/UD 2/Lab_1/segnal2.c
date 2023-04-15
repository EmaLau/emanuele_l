#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void gestore(int signum){
    printf("-> il processo %d sente il segnale %d\n", getpid(), signum);
}

int main(int argc, const char * argv[]) {
    signal(SIGINT, gestore);
    if(fork() == 0)
        printf("Figlio PID %d - gruppo PGID %d aspetta .. \n", getpid(), getpgid(getpid()));
    else
        printf("padre PID %d - gruppo PGID %d aspoetta ...\n", getpid(), getpgid(getpid()));
    pause();
    return 0;
}

