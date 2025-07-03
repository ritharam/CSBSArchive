#include <stdio.h>
int n;
struct process
{
    int at, bt, ft, status;
} rl[10];
int dispatcher(int time, int i)
{
    int index = -1;
    if (rl[i].status != 1 && rl[i].at <= time)
    {
        index = i;
    }
    return index;
}
void main()
{
    int cur_time, i, pid;
    printf("Enter the number of processess :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival & Burst time of Process %d :", i + 1);
        scanf("%d%d", &rl[i].at, &rl[i].bt);
    }
    i = 0;
    cur_time = 0;
    while (i < n)
    {
        pid = dispatcher(cur_time, i);
        if (pid != -1)
        {
            rl[pid].ft = cur_time + rl[pid].bt;
            rl[pid].status = 1;
            cur_time += rl[pid].bt;
        }
        else
        {
            continue;
        }
        i++;
    }
    printf("Process\tAT\tBT\tFT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, rl[i].at, rl[i].bt, rl[i].ft);
    }
}