#include <stdio.h>
#include <stdlib.h>

int *processors;
struct process
{
    int pid, at, bt, ft, status, sel;
} rq[10];

void dispatcher(int t, int n, int cpu)
{
    for (int i = 0; i < n; i++)
    {
        if (rq[i].status != 1 && rq[i].sel == 0 && rq[i].at <= t)
        {
            for (int j = 0; j < cpu; j++)
            {
                if (processors[j] == -1)
                {
                    rq[i].sel = 1;
                    processors[j] = i;
                    break;
                }
            }
        }
    }
}

void fcfsIO(int n, int cpu)
{
    for (int i = 0; i < cpu; i++)
    {
        processors[i] = -1;
    }
    int time = 0;
    int i = 0;
    while (i < n)
    {
        dispatcher(time, n, cpu);
        for (int k = 0; k < cpu; k++)
        {
            if (processors[k] != -1)
            {
                rq[processors[k]].bt--;
                if (rq[processors[k]].bt == 0)
                {
                    rq[processors[k]].status = 1;
                    rq[processors[k]].ft = time + 1;
                    processors[k] = -1;
                    i++;
                }
            }
        }
        time++;
    }
}

int main()
{
    FILE *fptr;
    fptr = fopen("mpsInput.txt", "r");
    int n, cpu;
    processors = (int *)malloc(cpu * sizeof(int));
    fscanf(fptr, "%d %d", &n, &cpu);
    for (int i = 0; i < n; i++)
    {
        fscanf(fptr, "%d %d", &rq[i].at, &rq[i].bt);
        rq[i].status = 0;
        rq[i].pid = i + 1;
        rq[i].sel = 0;
    }
    fclose(fptr);
    fcfsIO(n, cpu);
    printf("PID\tAT\tBT\tFT\tSTATUS\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", rq[i].pid, rq[i].at, rq[i].bt, rq[i].ft, rq[i].status);
    }
}