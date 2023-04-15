#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    int pid1;
    int pid2;
    pid1 = fork();
    if(pid1 == 0){
        while(1){
            printf("pid1 è vivo \n");
            sleep(1);
        }
    }
    pid2 = fork();
    if(pid2 == 0){
        while(1){
            printf("pid2 è vivo\n");
            sleep(1);
        }
    }
    sleep(1);
    kill(pid1, SIGSTOP);
    sleep(4);
    kill(pid1, SIGCONT);
    sleep(2);
    kill(pid1, SIGINT);
    kill(pid2, SIGINT);
    return 0;
}

