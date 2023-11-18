#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int globale;

void *codiceThread(void *arg){
    int i, x, y;
    for(i=0; i<20; i++){
        globale++;
        x = globale;
        y = globale * x;
        y = globale * x;
        printf(".");
        fflush(stdout);
    }
    return NULL;
}


int main(int argc, const char * argv[]) {
    pthread_t mioThread;
    int i;
    if(pthread_create(&mioThread, NULL, codiceThread, NULL)){
        printf("errore nella creazione del thread");
        abort();
    }
    for(i=0; i<20; i++){
        globale++;
        printf("o");
        sleep(1);
    }
    if(pthread_join(mioThread, NULL)){
        printf("errore nel join del thread");
        abort();
    }
    printf("\nglobale vale %d\n", globale);
    exit(0);
    return 0;
}
