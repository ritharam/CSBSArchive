#include <stdio.h>
#include <pthread.h>

int list[10], temp;

void *sort(void *index) {
    if ((int)index == 0)
        printf("Thread 1:");
    else
        printf("Thread 2:");

    int i, j;
    for (i = 0; i < (int)index + 5; i++)
        for (j = 0; j < (int)(index + 5) - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }

    for (i = (int)index; i < (int)index + 5; i++)
        printf("%d\t", list[i]);

    printf("\n");
    pthread_exit(NULL);
}

int main(void) {
    int i;
    for (i = 0; i < 10; i++)
        scanf("%d", &list[i]);

    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1, NULL, sort, (void *)0); // thread to sort list from 0 to 4
    pthread_create(&tid2, NULL, sort, (void *)5); // thread to sort list from 5 to 9

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
