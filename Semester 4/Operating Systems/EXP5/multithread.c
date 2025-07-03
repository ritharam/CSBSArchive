#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h> 
#include <pthread.h>

int flag = 0;

void *sthread() 
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Write Data : ");
    fgets(str, 1024, stdin); 
    printf("Data written in memory: %s\n", str);
    shmdt(str);
    flag = 1;
    pthread_exit(NULL);
}

void *rthread() 
{
    while (flag == 0);
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Data read from memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
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