#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define MUTEX 0
#define EMPTY 1
#define FILLED 2

struct shared {
    sem_t sem[3];
    int buf[5];
    int rear, front;
} *s;

void* producer(void* count) {
    int n = 1;
    int self = * (int*) count;
    while (n <= 5) {
        sem_wait(&(s->sem[EMPTY]));
        sem_wait(&(s->sem[MUTEX]));

        s->rear = (s->rear + 1) % 5;
        s->buf[s->rear] = n;
        n++;
        printf("[Producer %d] %d\n", self, s->buf[s->rear]);

        sem_post(&(s->sem[MUTEX]));
        sem_post(&(s->sem[FILLED]));
        sleep(1);
    }
}

void* consumer(void* count) {
    int i;
    int self = * (int*) count;
    for (i = 0; i < 5; i++) {
        sem_wait(&(s->sem[FILLED]));
        sem_wait(&(s->sem[MUTEX]));

        s->front = (s->front + 1) % 5;
        printf("[Consumer %d] %d\n", self, s->buf[s->front]);

        sem_post(&(s->sem[MUTEX]));
        sem_post(&(s->sem[EMPTY]));
        sleep(1);
    }
}

int main(int argc, char** argv) {
    pthread_t threads[5];
    int tno[5];
    char ch;
    int shmid, is_init, *temp;
    shmid = shmget(1234, sizeof(struct shared), 0600 | IPC_CREAT | IPC_EXCL);
    is_init = shmid == -1;

    if (is_init)
        shmid = shmget(1234, sizeof(struct shared), 0600);
    s = shmat(shmid, NULL, 0);

    if (!is_init) {
        printf("Initializing shared memory.\n");
        sem_init(&(s->sem[MUTEX]), 1, 1);
        sem_init(&(s->sem[EMPTY]), 1, 5);
        sem_init(&(s->sem[FILLED]), 1, 0);
        s->rear = s->front = -1;
    }
    printf("Producer (p) / Consumer (c)? ");
    ch = getchar();
    switch(ch) {
        case 'p':
            for (int i = 0; i < 5; i++) {
                tno[i] = i + 1;
                pthread_create(&threads[i], 0, producer, (void*) &tno[i]);
            }
            for (int i = 0; i < 5; i++)
                pthread_join(threads[i], NULL);
            break;
        case 'c':
            for (int i = 0; i < 5; i++) {
                tno[i] = i + 1;
                pthread_create(&threads[i], 0, consumer, (void*) &tno[i]);
            }
            for (int i = 0; i < 5; i++)
                pthread_join(threads[i], NULL);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
