#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVar = PTHREAD_COND_INITIALIZER;

void produci(void *parametro) {
    printf("Avvio della esecuzione del %s. \n", (char*)parametro);
    sleep(2);
    printf("Trhead 1 tenta di entrare nella sezione critica. \n");
    pthread_mutex_lock(&mutex);
    printf("Thread 1 nella sezione critica - ha bloccato il mutex. \n");
    printf("Thread 1 produce... \n");
    sleep(1);
    printf("Thread 1 si sospende sulla condition variable. \n");
    pthread_cond_wait(&condVar, &mutex);
    printf("Thread 1 riprende l'esecuzione. \n");
    printf("Thread 1 esce dalla sezione critica - rilascia mutex. \n");
    pthread_mutex_unlock(&mutex);
    printf("Thread 1 puo' terminare. \n");
}

void consuma(void *parametro) {
    printf("Avvio della esecuzione del %s. \n", (char*)parametro);
    sleep(5);
    printf("Thread 2 tenta di entrare nella sezione critica. \n");
    pthread_mutex_lock(&mutex);
    printf("Thread 2 nella sezione critica - ha bloccato mutex. \n");
    printf("Thread 2 consuma ...\n");
    sleep(1);
    printf("Thread 2 sblocca chi è in attesa sulla condition variabile. \n");
    pthread_cond_signal(&condVar);
    printf("Thread 2 ora esce dalla sezione critica - rilascia mutex. \n");
    pthread_mutex_unlock(&mutex);
    printf("Thread 2 puo' terminare. \n");
}


int main(int argc, const char * argv[]) {
    pthread_t thread1, thread2;
    char *nome1 = "Thread 1";
    char *nome2 = "Thread 2";
    if(pthread_create(&thread1, NULL, &produci, nome1) != 0) {
        perror("Errore nella creazione del primo thread. \n");
        exit(1);
    }
    if(pthread_create(&thread2, NULL, &consuma, nome2) != 0){
        perror("Errore nella creazione del secondo thread. \n");
        exit(1);
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

