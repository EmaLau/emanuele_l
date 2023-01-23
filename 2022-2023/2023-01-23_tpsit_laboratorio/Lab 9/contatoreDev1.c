
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define TANTI 10
int globale;

void *cosaFaThread(void *arg){
    int i, locale;
    for(i=0; i<TANTI; i++){
        printf("\n.Ho letto %d", globale);
        sleep(1);
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t mioThread;
    int i;
    if (pthread_create(&mioThread, NULL, cosaFaThread, NULL)){
        printf("Errore nella creazione del thraed.");
        abort();
    }
    for(i =0; i<TANTI; i++){
        globale = globale+1;
        printf("\nHo scritto %d",globale);
        fflush(stdout);
        sleep(1);
    }
    if(pthread_join(mioThread, NULL)){
        printf("Errore nel join del thread");
        abort();
    }
    printf("\nglobale vale %d\n", globale);
    exit(0);
    
    return 0;
}
