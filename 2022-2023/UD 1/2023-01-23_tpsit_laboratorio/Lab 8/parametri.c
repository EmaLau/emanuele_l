#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int globale = 30;

void *thread(void *arg){
    int dato;
    dato = *(int*) arg + 20;
    srand(time(NULL));
    globale = globale * (rand() % 7)+dato;
    if(globale<100)
        pthread_exit((int*)0);
    else
        pthread_exit((int*)1);
}

int main(int argc, const char * argv[]) {
    pthread_t tid;
    int ingresso;
    void *ritorno;
    ingresso = 10;
    pthread_create(&tid, NULL, thread, (void*) &ingresso);
    if(pthread_join(tid, &ritorno)==0){
        printf("Valore di globale : %d\n", globale);
        printf("Valore di ingresso : %d\n", ingresso);
        printf("Valore di ritorno : %d\n", ritorno);
        exit(0);
    }else
        printf("erorre join nel thread!");
    exit(-1);
    return 0;
}
