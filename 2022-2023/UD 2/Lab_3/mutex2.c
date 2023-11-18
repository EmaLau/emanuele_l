#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define TANTI 10
int buffer =0;
pthread_mutex_t mutex;

void *cod_thread1(void *arg){
        int accessi1 =0;
        while(buffer<TANTI){
            pthread_mutex_lock(&mutex);
            accessi1++;
            buffer++;
            printf("accessi di T1: %d valore buffer %d\n", accessi1, buffer);
            pthread_mutex_unlock(&mutex);
            sleep((int) (5.0 * rand()/(RAND_MAX + 1.0)));
        }
    pthread_exit(0);
    return NULL;
}

void *cod_thread2(void *arg){
        int accessi1 =0;
            pthread_mutex_lock(&mutex);
            accessi1++;
            buffer++;
            printf("accessi di T1: %d valore buffer %d\n", accessi1, buffer);
            sleep((int) (5.0 * rand()/(RAND_MAX + 1.0)));
    pthread_exit(0);
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t tid1, tid2;
    pthread_mutex_init(&mutex, NULL);
    if(pthread_create(&tid1, NULL, cod_thread1, NULL) < 0){
        fprintf(stderr, "errore nella creazione del thread 1 \n");
        exit(1);
    }
    if(pthread_create(&tid2, NULL, cod_thread2, NULL) < 0){
        fprintf(stderr, "errore nella crazione del thread 2");
        exit(1);
    }
    pthread_join(tid1, NULL);
    pthread_join(tid1, NULL);
    return 0;
}

