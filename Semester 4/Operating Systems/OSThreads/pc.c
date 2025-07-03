#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
int front = -1;
int rear = -1;
int array[5];

sem_t mutex;
sem_t emptyCount;
sem_t fullCount;
int p_tid;
int c_tid;
int produce_item();
void insert_item(int);
int remove();
void * produce()
{
int item;
while(1)
{
item=produce_item();
sem_wait(&emptyCount);
sem_wait(&mutex);
printf("\nproducer entering the critical section");
insert_item(item);
printf("\n producer %d inserting an item %d at %d",item, rear);
sem_post(&mutex);
sem_post(&fullCount);
}
}
void *consumer()
{
int item;
while(1)
{
sleep(20);
sem_wait(&fullCount);
sem_wait(&mutex);
printf("\n sonsumer %d entering the critical regiion");
item=remove_item();
printf("\n comsumer %d leaving the critical region");
sem_post(&mutex);
sem_post(&emptyCount);
printf("\n consumer %d consumed item %d",item);
}
}

int produce_item()
{
static int a=100;
return a++;
}
void insert_item(int item)
{
rear = rear+1;
rear = rear % 5;
array[rear] = item;
}
int remove_item()
{
front = front+1;
front = front%5;
int item= array[front];
return item;
}
int main()
{
int a[8] = {0,1,2,3,4};
int i;
pthread_attr_t *attr = NULL;
pthread_t p_tid;
pthread_t c_tid;
sem_init(&mutex,0,1);
sem_init(&emptyCount,0,5);
sem_init(&fullCount,0,0);
pthread_create(&p_tid,attr,produce,0);
pthread_create(&c_tid,attr,consumer,0);
pthread_join(p_tid,NULL);
pthread_join(c_tid,NULL);
return 0;
}
