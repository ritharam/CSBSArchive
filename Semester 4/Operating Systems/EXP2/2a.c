#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
	printf("Key of shared memory : %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Proces attached at %p\n", shared_memory);
	printf("Enter some data to write to shared memory : \n");
	read(0,buff,100);
	strcpy(shared_memory, buff);
	printf("You wrote : %s\n", (char*)shared_memory);
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)2345, 1024, 0666);
	printf("Key of shared memory : %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Proces attached at %p\n", shared_memory);
	printf("Data read from shared memory is : %s\n", (char*)shared_memory);
}