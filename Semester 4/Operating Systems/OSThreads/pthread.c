#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *sthread() // sender thread
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, NULL, 0);
    printf("Write Data : ");
    fgets(str, 1024, stdin);
    // Removing newline character if present
    strtok(str, "\n");
    printf("Data written in memory: %s\n", str);
    shmdt(str);
    pthread_exit(NULL);
}

void *rthread() // receiver thread
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, NULL, 0);
    printf("Data read from memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL); // Detaching before removing
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, sthread, NULL);
    pthread_create(&tid2, NULL, rthread, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
