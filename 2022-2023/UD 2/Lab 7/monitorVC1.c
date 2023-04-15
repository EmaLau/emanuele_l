#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 4
#define FINE (-1)
typedef struct {
    int buffer;
    pthread_mutex_t mutex;
    pthread_cond_t pieno;
    pthread_cond_t vuoto;
}monitor;
monitor bufferComune;
void inizializza (monitor *mpc){
    pthread_mutex_init(&mpc->mutex, NULL);
    pthread_cond_init(&mpc->pieno, NULL);
    pthread_cond_init(&mpc->vuoto, NULL);
    mpc->buffer =0;
}
void inserisci(monitor *mpc, int data){
    pthread_mutex_lock(&mpc->mutex);
    if(mpc->buffer != 0){
        pthread_cond_wait(&mpc->vuoto, &mpc->mutex);
    }
    if(mpc->buffer == 0)
        mpc->buffer = data;
    pthread_cond_signal(&mpc->pieno);
    pthread_mutex_unlock(&mpc->mutex);
}

int estrai (monitor *mpc){
    int data;
    pthread_mutex_lock(&mpc->mutex);
    if(mpc->buffer == 0){
        pthread_cond_wait(&mpc->pieno, &mpc->mutex);
    }
    if(mpc->buffer != 0){
        data = mpc->buffer;
        mpc->buffer = 0;
    }
    pthread_cond_signal(&mpc->vuoto);
    pthread_mutex_unlock(&mpc->mutex);
    return data;
}

void *produttore(void *data){
    int n;
    for(n=1; n<= MAX; n++){
        printf("produttore: dato %d. prodotto \n", n);
        inserisci(&bufferComune, n);
        printf("produttore: %d ...inserito\n", n);
    }
    inserisci(&bufferComune, FINE);
    return NULL;
}

void *consumatore(void *data){
    int dato;
    do{
        dato = estrai(&bufferComune);
        if(dato != FINE)
            printf("consumatore: dato %d ...consumato\n", dato);
    }while(dato != FINE);
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t pid1, pid2;
    void *retval;
    inizializza(&bufferComune);
    pthread_create(&pid1, NULL, produttore, 0);
    pthread_create(&pid2, NULL, consumatore, 0);
    
    pthread_join(pid1, &retval);
    pthread_join(pid2, &retval);
    return 0;
}

