#include <stdio.h>
int n;
struct process
{
    int at, bt, bt1, ft, status;
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
    int cur_time = 0, i, pid = 0;
    printf("Enter the number of processess :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival & Burst time %d :", i + 1);
        scanf("%d%d", &rl[i].at, &rl[i].bt);
        rl[i].status = 0;
        rl[i].bt1 = rl[i].bt;
    }
    i = 0;
    cur_time = 0;
    while (pid != -1)
    {
        pid = dispatcher(cur_time);
        if (pid != -1)
        {
            if (rl[pid].bt == 1)
            {
                rl[pid].ft = cur_time + 1;
                rl[pid].status = 1;
                cur_time++;
            }
            else
            {
                rl[pid].bt--;
                cur_time++;
            }
        }
    }
    printf("Process\tAT\tBT\tFT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, rl[i].at, rl[i].bt1, rl[i].ft);
    }
}