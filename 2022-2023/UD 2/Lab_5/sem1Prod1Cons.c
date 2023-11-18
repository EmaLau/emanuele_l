#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
const int VOLTE = 5;

int buffer;
int conta = 0;
static sem_t mio_sem;

void *produci(void *arg){
    int avanti = 1;
    while (avanti) {
        sem_wait(&mio_sem);
        if(conta < VOLTE){
            if(buffer == 0){
                buffer = conta++;
                printf("T1: scritto %d \n", buffer);
            }
        }else{
            avanti = 0;
            printf("T1 ha finito \n");
        }
        sem_post(&mio_sem);
    }
    fflush(stdout);
    pthread_exit(0);
    return NULL;
}

void *consuma(void *threadid){
    int avanti = 1;
    while(avanti){
        sem_wait(&mio_sem);
        if(conta < VOLTE){
            if(buffer > 0){
                conta = buffer;
                buffer = 0;
                printf("T2: letto %d \n", conta);
            }
        }else{
            avanti = 0;
            printf("T2 ha fatto \n");
        }
        sem_post(&mio_sem);
    }
    fflush(stdout);
    pthread_exit(0);
    return NULL;
}


int main(int argc, const char * argv[]) {
    pthread_t tid1, tid2;
    sem_init(&mio_sem, 0, 1);
    if(pthread_create(&tid1, NULL, produci, NULL) < 0){
        fprintf(stderr, "errore nella creazione del thread 1\n");
        exit(1);
    }
    if(pthread_create(&tid2, NULL, consuma, NULL) < 0){
        fprintf(stderr, "errore nella creazione del thread 2\n");
        exit(2);
    }
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}

