#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

sem_t mutex;
sem_t rwmutex;
int readcount = 0;
int rcount = 0;

void *reader() {
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) {
        sem_wait(&rwmutex);
    }
    sem_post(&mutex);

    // Reading...
    printf("\nReader %ld is inside\n", pthread_self()%10);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0) {
        sem_post(&rwmutex);
    }
    sem_post(&mutex);

    printf("\nReader %ld is leaving\n", pthread_self()%10);

    pthread_exit(NULL);
}

void *writer() {
    sem_wait(&rwmutex);

    // Writing...
    printf("\nWriter %ld is updating\n", pthread_self()%10);

    sem_post(&rwmutex);

    pthread_exit(NULL);
}

int main() {
    int n2 = 10; // Number of readers and writers

    pthread_t r_tid[n2];
    pthread_t w_tid[n2];

    sem_init(&mutex, 0, 1);
    sem_init(&rwmutex, 0, 1);

    for (int i = 0; i < n2; i++) {
        pthread_create(&r_tid[i], NULL, reader, NULL);
        pthread_create(&w_tid[i], NULL, writer, NULL);
    }

    for (int i = 0; i < n2; i++) {
        pthread_join(r_tid[i], NULL);
        pthread_join(w_tid[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&rwmutex);

    return 0;
}
