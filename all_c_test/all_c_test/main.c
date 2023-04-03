#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void gestore(int segnale){
    printf("...ricevuto segnale %d\n", segnale);
    sleep(2);
    printf("...terminazione handler segnale %d\n", segnale);
}

int main(int argc, const char * argv[]) {
    int k;
    signal(SIGINT, gestore);
    for(k =1;; k++){
        printf("%d\n", k);
        sleep(1);
    }
        
    return 0;
}
