#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define N 5
#define PENSA 0
#define ATTESA 1
#define MANGIA 2
#define DESTRA (x + 1) % N
#define SINISTRA (x - 1 + N) % N

pthread_mutex_t mutex, mutex_f[N];
int stato[N];

void pensa(int i){
    printf("\nFILOSOFO %d: sto pensando ...", i);
    sleep(rand()%N);
}
void mangia(int i){
    printf("1n FILOSOFO %d: sto mangiando ...", i);
    sleep(rand()%N);
}

void posa(int i){
    pthread_mutex_lock(&mutex);
    stato[i] = PENSA;
    pthread_mutex_unlock(&mutex_f[i]);
    pthread_mutex_unlock(&mutex);
}


void controlloPosate(int i){
    pthread_mutex_lock(&mutex);
    printf("\nFOLOSOFO %d: non ho trovato le posate", i);
    stato[i] = ATTESA;
    printf("\nFILOSOFO %d: ...posate trovate...", i);
    
}

void prendi(int i){
    pthread_mutex_lock(&mutex);
    printf("\n FILOSOFO %d: ho fame e aspetto le forchette ...", i);
    stato[i] = ATTESA;
    controlloPosate(i);
    printf("\nFILOSOFO %d: ...ora prendo le forchette e mangio", i);
    pthread_mutex_lock(&mutex_f[i]);
    pthread_mutex_unlock(&mutex);
}

void *filosofo(void *x){
    int k = (int)x;
    while(1){
        pensa(k);
        prendi(k);
        mangia(k);
        posa(k);
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    int x;
    srand((int)time(NULL));
    pthread_t filo[N];
    pthread_mutex_init(&mutex, NULL);
    for(x=0; x < N; x++)
        pthread_mutex_init(&mutex_f[x], NULL);
    for(x=0; x < N; x++){
        pthread_create(&filo[N], NULL, (void *)filosofo, (void *)x);
        sleep(1);
    }
    pthread_exit(0);
    return 0;
}

