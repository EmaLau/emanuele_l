#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
const int VOLTE = 33;
const int NUM_THREAD_P = 3;
const int NUM_THREAD_C = 8;
const int FALSO = 0;
const int VERO = 1;

char buffer = 'a'-1;
int scritti = 0;
int letti = 0;
int fine = 0;
sem_t pieno, vuoto;
pthread_mutex_t mutex;

void *produci(void *threadid){
    long tid;
    tid = (long) threadid;
    printf("\n Ciao a tutti: sono il thread produci #%d!", tid);
    do{
        sleep(rand() %3);
        sem_wait(&vuoto);
        pthread_mutex_lock(&mutex);
        if(scritti < VOLTE){
            buffer++;
            scritti++;
            printf("\n produci #%ld %d", tid, scritti);
            fflush(stdout);
        }else{
            fine = VERO;
        }
        sem_post(&pieno);
        pthread_mutex_unlock(&mutex);
        
    }while(scritti < VOLTE);
    printf("\n produci #%ld ha funito", tid);
    fflush(stdout);
    sem_post(&vuoto);
    return NULL;
}

void *consuma(void *threadid){
    long tid;
    tid = (long) threadid;
    printf("\n Ciao a tutti: sono il thread consuma #%ld!", tid);
    char miobuffer = '\x0';
    do{
        sleep(rand() %3);
        sem_wait(&pieno);
        pthread_mutex_lock(&mutex);
        if(letti < scritti){
            miobuffer = buffer;
            letti++;
            printf("\n consuma #%ld ha letto %c : %d di %d", tid, miobuffer, letti, scritti);
            fflush(stdout);
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&vuoto);
    }while((fine == FALSO));
    printf("\n consuma #%ld ha finito", tid);
    fflush(stdout);
    sem_post(&pieno);
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t thread_P[NUM_THREAD_P];
    pthread_t thread_C[NUM_THREAD_C];
    long tc, tp;
    printf("\nInizio elaborazione...");
    sem_init(&pieno, 0, 0);
    sem_init(&vuoto, 0, 1);
    
    for(tp = 0; tp <NUM_THREAD_P; tp++){
        if(pthread_create(thread_P+tp, NULL, produci, NULL) < 0){
            fprintf(stderr, "errore nella craezione del thread P %d\n", tc);
            exit(1);
        }
    }
    for(tc = 0; tc < NUM_THREAD_C; tc++){
        if(pthread_create(thread_C+tc, NULL, consuma, NULL) < 0){
            fprintf(stderr, "errore nella creazione del thread C%d\n", tc);
            exit(1);
        }
    }
    for(tp = 0; tp < NUM_THREAD_P; tp++)
        pthread_join(thread_P[tp], NULL);
    for(tc = 0; tc < NUM_THREAD_C; tc++)
        pthread_join(thread_C[tc], NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&pieno);
    sem_destroy(&(vuoto));
    
    printf("\n Fine elaborazione ! \n");
    fflush(stdout);
    return 0;
}

