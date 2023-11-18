
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int parametroOUT;

void* codice(void *arg){
    srand(time(NULL));
    parametroOUT = (rand()%6) +1;
    pthread_exit((void*) &parametroOUT);
}

int main(int argc, const char * argv[]) {
    int dadoEstratto, *risultato;
    pthread_t t1;
    pthread_create(&t1, NULL, codice, NULL);
    pthread_join(t1, (void*) &risultato);
    printf("dado estratto: %d\n", *risultato);
    return 0;
}
