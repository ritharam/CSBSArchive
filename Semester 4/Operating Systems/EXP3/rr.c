#include <stdio.h>
#include <conio.h>

int Q[10], front = -1, rear = -1, n, run = -1;

void Push(int p_id)
{
    if (front == -1)
    {
        front = rear = 0;
        Q[front] = p_id;
    }
    else
    {
        rear++;
        Q[rear] = p_id;
    }
}

int Pop()
{
    int val, i;
    if (rear == -1)
        return -1;
    else if (rear == 0)
    {
        val = Q[front];
        front = rear = -1;
        return val;
    }
    else
    {
        val = Q[front];
        {
            for (i = 0; i <= rear - 1; i++)
                Q[i] = Q[i + 1];
        }
        rear--;
        return val;
    }
}
struct process
{
    int at;
    int st;
    int status;
    int ft;
    int q;
} RR_QUEUE[10];

int dispatcher(int time)
{
    int i, pid;
    for (i = 0; i < n; i++)
    {
        if (RR_QUEUE[i].status != 1)
        {
            if (RR_QUEUE[i].at <= time && run != i)
            {
                if (RR_QUEUE[i].q == 0)
                    Push(i);
                RR_QUEUE[i].q = 1;
            }
        }
    }
    if (run != -1)
    {
        Push(run);
        run = -1;
    }
    pid = Pop();
    return pid;
}
int main()
{
    int i, cur_time, pid, tq;
    printf("Enter number of processes:");
    scanf("%d", &n);
    printf("Enter the time quantum:");
    scanf("%d", &tq);
    for (i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        printf("***********\n");
        printf("Enter Arrival Time:");
        scanf("%d", &RR_QUEUE[i].at);
        printf("Enter Service Time:");
        scanf("%d", &RR_QUEUE[i].st);
        RR_QUEUE[i].status = 0;
        RR_QUEUE[i].q = 0;
    }
    i = 0;
    cur_time = 0;
    while (i < n)
    {
        pid = dispatcher(cur_time);

        if (pid != -1)
        {
            run = pid;
            if (RR_QUEUE[pid].st > tq)
            {
                RR_QUEUE[pid].st = RR_QUEUE[pid].st - tq;
                cur_time = cur_time + tq;
            }
            else if (RR_QUEUE[pid].st == tq)
            {
                RR_QUEUE[pid].st = 0;
                cur_time = cur_time + tq;
                RR_QUEUE[pid].ft = cur_time;
                RR_QUEUE[pid].status = 1;
                run = -1;
                i++;
            }
            else
            {
                cur_time = cur_time + RR_QUEUE[pid].st;
                RR_QUEUE[pid].st = 0;
                RR_QUEUE[pid].ft = cur_time;
                RR_QUEUE[pid].status = 1;
                run = -1;
                i++;
            }
        }
        else
            cur_time++;
    }
    printf("\n");
    printf("Process\t Arrival Time\t Service Time\t Finish Time\n");
    printf("*******\t ************\t ************\t ***********\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i, RR_QUEUE[i].at, RR_QUEUE[i].st, RR_QUEUE[i].ft);
    }
    getch();
}