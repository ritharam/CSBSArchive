#include <stdio.h>
int n;
struct process
{
    int at, bt, ft, status;
} rl[10];
int dispatcher(int time)
{
    int index = -1, max = 999;
    for (int i = 0; i < n; i++)
    {
        if (rl[i].status != 1 && rl[i].at <= time && rl[i].bt < max)
        {
            max = rl[i].bt;
            index = i;
        }
    }
    return index;
}
void main()
{
    int cur_time = 0, i, pid;
    printf("Enter the number of processess :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival & Burst time %d :", i + 1);
        scanf("%d%d", &rl[i].at, &rl[i].bt);
        rl[i].status = 0;
    }
    i = 0;
    cur_time = 0;
    while (i < n)
    {
        pid = dispatcher(cur_time);
        if (pid != -1)
        {
            rl[pid].ft = cur_time + rl[pid].bt;
            rl[pid].status = 1;
            cur_time += rl[pid].bt;
        }
        i++;
    }
    printf("Process\tAT\tBT\tFT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, rl[i].at, rl[i].bt, rl[i].ft);
    }
}