#include<stdio.h>
#include<pthread.h>
#include<sys/shm.h>

int flag[2] = {0, 0}, turn = 0, count;

void lock(int self) {
	flag[self] = 1;
	turn = 1 - self;
	while(flag[1-self]==1 && turn==1-self);
}

void unlock(int self) {
	flag[self] = 0;
}

void *thread0(void *s) {
	int i = 0, self = (int *)s;
	while(1) {
		lock(self);
		printf("P%d is in critical section\n", self);
		if(count < 100)
			count++;
		printf("Value of count: %d\n", count);
		unlock(self);
	}
}

void *thread1(void *s) {
	int i = 0, self = (int *)s;
	while(1) {
		lock(self);
		printf("P%d is in critical section\n", self);
		if(count > 0)
			count--;
		printf("Value of count: %d\n", count);
		unlock(self);
		i++;
	}
}

int main() {
	pthread_t p1, p2;
	
	pthread_create(&p1, NULL, thread0, (void *)0);
	pthread_create(&p2, NULL, thread1, (void *)1);
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	return 0;
}
