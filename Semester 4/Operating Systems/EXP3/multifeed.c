#include <stdio.h>
struct process
{
    int pid;
    int bt;
    int rbt; 
    int ft;
} rdq[10];
int n;
void main()
{
    int tqq[10], completed = 0, qlevel = 0, qcount, i, tq, cur_time = 0;
    printf("Enter number of queues");
    scanf("%d", &qcount);
    for (i = 0; i < qcount; i++)
    {
        printf("Enter time quantum of Q%d", i);
        scanf("%d", &tqq[i]);
    }
    printf("Enter number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter BT of process P%d: ", i);
        scanf("%d", &rdq[i].bt);
        rdq[i].rbt = rdq[i].bt;
    }
    while (completed < n)
    {
        if (qlevel < qcount) 
        {
            tq = tqq[qlevel];
            qlevel++;
        }
        for (i = 0; i < n; i++)
        {
            if (rdq[i].rbt != 0) 
            {
                if (rdq[i].rbt <= tq)
                {
                    cur_time += rdq[i].rbt;
                    rdq[i].rbt = 0;
                    rdq[i].ft = cur_time;
                    completed++;
                }
                else 
                {
                    cur_time += tq;
                    rdq[i].rbt -= tq;
                }
            }
        }
    }
    printf("PID\t BT\t FT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\n", i, rdq[i].bt, rdq[i].ft);
    }
}