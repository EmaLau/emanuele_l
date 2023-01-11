#include <stdio.h>
#include <pthread/pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread1 (void* arg){
    sleep(rand() %1);
    printf("DIN");
    fflush(stdout);
    return 0;
}

void* thread2 (void* arg){
    sleep(rand() %2);
    printf("DON");
    fflush(stdout);
    return 0;
}

void* thread3 (void* arg){
    sleep(rand() %3);
    printf("DAN");
    fflush(stdout);
    return 0;
}


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    pthread_t miothread1, miothread2, miothread3;
    pthread_create(&miothread1, NULL, &thread1, NULL);
    pthread_create(&miothread2, NULL, &thread2, NULL);
    pthread_create(&miothread3, NULL, &thread3, NULL);
    pthread_join(miothread1, NULL);
    pthread_join(miothread2, NULL);
    pthread_join(miothread3, NULL);
    return 0;
}
