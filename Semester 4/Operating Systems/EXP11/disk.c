#include <stdio.h>
#include <stdlib.h>

int FCFS(int *req, int n, int cur)
{
    int totMov = 0;
    for (int i = 0; i < n; i++)
    {
        totMov += abs(req[i] - cur);
        cur = req[i];
    }
    return totMov;
}

int findShortestSeekTime(int *req, int n, int cur, int *visited)
{
    int shortest = 99999;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && abs(req[i] - cur) < shortest)
        {
            shortest = abs(req[i] - cur);
            index = i;
        }
    }
    return index;
}

int SSTF(int *req, int n, int cur)
{
    int totMov = 0;
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int index = findShortestSeekTime(req, n, cur, visited);
        totMov += abs(req[index] - cur);
        cur = req[index];
        visited[index] = 1;
    }
    return totMov;
}

int SCAN(int *req, int n, int cur, int direction)
{
    int totMov = 0;
    int head = cur;
    int start = 0, end = 199;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (req[j] > req[j + 1])
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int index;
    for (index = 0; index < n; index++)
    {
        if (req[index] >= cur)
        {
            break;
        }
    }

    if (direction == 1)
    {
        for (int i = index; i < n; i++)
        {
            totMov += abs(req[i] - head);
            head = req[i];
        }
        totMov += end - head;
        head = end;
        for (int i = index - 1; i >= 0; i--)
        {
            totMov += abs(req[i] - head);
            head = req[i];
        }
    }
    else
    {
        for (int i = index - 1; i >= 0; i--)
        {
            totMov += abs(req[i] - head);
            head = req[i];
        }
        totMov += head - start;
        head = start;
        for (int i = index; i < n; i++)
        {
            totMov += abs(req[i] - head);
            head = req[i];
        }
    }
    return totMov;
}

int main()
{
    int n;
    printf("Enter the number of req: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    int cur;
    printf("Enter the cur position of the disk head: ");
    scanf("%d", &cur);

    int totMovFCFS = FCFS(req, n, cur);
    printf("Total head movement using FCFS: %d\n", totMovFCFS);

    int totMovSSTF = SSTF(req, n, cur);
    printf("Total head movement using SSTF: %d\n", totMovSSTF);

    int direction;
    printf("Enter the direction of movement for SCAN (1 for towards end, -1 for towards start): ");
    scanf("%d", &direction);
    int totMovSCAN = SCAN(req, n, cur, direction);
    printf("Total head movement using SCAN: %d\n", totMovSCAN);

    return 0;
}
