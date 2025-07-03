#include <stdio.h>

int n;
struct process
{
    int at, ato, bto, bt, io, bt2, ft, status;
} rl[10];

int dispatcher(int time)
{
    int index = -1, max = 999;
    for (int i = 0; i < n; i++)
    {
        if (rl[i].status != 2 && rl[i].at <= time && rl[i].at < max)
        {
            max = rl[i].at;
            index = i;
        }
    }
    return index;
}

void main()
{
    int cur_time, i, pid = 0, count;
    printf("Enter the number of processess :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter AT & BT & IO & BT2 of Process %d :", i + 1);
        scanf("%d%d%d%d", &rl[i].at, &rl[i].bt, &rl[i].io, &rl[i].bt2);
        rl[i].status = 0;
        rl[i].ato = rl[i].at;
        rl[i].bto = rl[i].bt;
    }
    i = 0;
    cur_time = 0;
    count = 2 * n;

    while (count > 0)
    {
        pid = dispatcher(cur_time);
        if (pid != -1)
        {
            if (rl[pid].status == 0)
            {
                cur_time += rl[pid].bt;
                rl[pid].at = cur_time + rl[pid].io;
                rl[pid].bt = rl[pid].bt2;
                rl[pid].status = 1;
            }
            else if (rl[pid].status == 1)
            {
                rl[pid].ft = cur_time + rl[pid].bt;
                rl[pid].status = 2;
                cur_time += rl[pid].bt;
            }
            count--;
        }
        else
        {
            cur_time++;
        }
    }
    printf("Process\tAT\tBT\tFT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, rl[i].ato, rl[i].bto, rl[i].ft);
    }
}