#include <stdio.h> 

struct process{
    int at;     // arrival time
    int bt;     // service time
    int pr;     // priority
    int status; // 1 completed, 0 - not comple
    int ft;     // finish time
}ready_list[10];

int n;
int main()
{
    int i, cur_time, pid;
    printf("Enter number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("***********\n");
        printf("Enter Arrival Time:");
        scanf("%d", &ready_list[i].at);
        printf("Enter Burst Time:");
        scanf("%d", &ready_list[i].bt);
        printf("Priority (1-10):");
        scanf("%d", &ready_list[i].pr);
        ready_list[i].status = 0;
    }
    i=0; cur_time=0;
    while(i<n)
    {
        pid = dispatcher(cur_time);
        ready_list[pid].ft = cur_time + ready_list[pid].bt;
        ready_list[pid].status = 1;
        cur_time += ready_list[pid].bt;
        i++;
    }
    printf("Process\tAT\tBT\tFT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, ready_list[i].at, ready_list[i].bt, ready_list[i].ft);
    }
}

int dispatcher(int time)
{
    int i, high_pr = 999, index = -1;
    for (i=0;i<n;i++)
    {
        if (ready_list[i].status != 1)
        if (ready_list[i].at <= time)
        if (ready_list[i].pr < high_pr)
        {
            high_pr = ready_list[i].pr;
            index = i;
        }
    }
    return index;
}