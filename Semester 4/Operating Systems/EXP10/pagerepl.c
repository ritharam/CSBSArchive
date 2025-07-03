#include <stdio.h>

void FIFO(int page[], int p_count, int f_count)
{
    int frames[100];
    int fault = 0, hit = 0;
    int i, j, k;
    for (i = 0; i < f_count; ++i)
        frames[i] = -1;
    printf("\nPage Reference\t Page Frames\n");
    for (i = 0; i < p_count; ++i)
    {
        printf("%d\t\t", page[i]);
        int page_found = 0;
        for (j = 0; j < f_count; ++j)
        {
            if (frames[j] == page[i])
            {
                page_found = 1;
                hit++;
                break;
            }
        }
        if (!page_found)
        {
            frames[fault % f_count] = page[i];
            fault++;
        }
        for (j = 0; j < f_count; ++j)
            printf("%d\t", frames[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults (FIFO): %d\n", fault);
    printf("Total Page Hits (FIFO): %d\n", hit);
}

void LRU(int page[], int p_count, int f_count)
{
    int frames[100];
    int frame_age[100];
    int fault = 0, hit = 0;
    int i, j, k;
    for (i = 0; i < f_count; i++)
    {
        frames[i] = -1;
        frame_age[i] = p_count + 1;
    }
    printf("\nPage Reference\t Page Frames\n");
    for (i = 0; i < p_count; i++)
    {
        printf("%d\t\t", page[i]);
        int page_found = 0;
        for (j = 0; j < f_count; ++j)
        {
            if (frames[j] == page[i])
            {
                page_found = 1;
                hit++;
                frame_age[j] = 0;
                break;
            }
        }
        if (!page_found)
        {
            int k = 0;
            int max_age = frame_age[0];
            for (j = 1; j < f_count; ++j)
            {
                if (frame_age[j] > max_age)
                {
                    max_age = frame_age[j];
                    k = j;
                }
            }
            frames[k] = page[i];
            frame_age[k] = 0;
            fault++;
        }
        for (k = 0; k < f_count; ++k)
        {
            if (frames[k] != -1)
                frame_age[k]++;
        }
        for (j = 0; j < f_count; ++j)
            printf("%d\t", frames[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults (LRU): %d\n", fault);
    printf("Total Page Hits (LRU): %d\n", hit);
}

void Optimal(int page[], int p_count, int f_count)
{
    int frames[100];
    int fault = 0, hit = 0;
    int i, j, k;

    for (i = 0; i < f_count; ++i)
        frames[i] = -1;

    printf("\nPage Reference\t Page Frames\n");
    for (i = 0; i < p_count; ++i)
    {
        printf("%d\t\t", page[i]);
        int page_found = 0;
        for (j = 0; j < f_count; ++j)
        { 
            if (frames[j] == page[i])
            {
                page_found = 1;
                hit++;
                break;
            }
        }
        if (!page_found)
        {
            int max_dist = -1;
            int index = -1;
            for (j = 0; j < f_count; ++j)
            {
                int dist = 0;
                for (k = i + 1; k < p_count; ++k)
                {
                    if (frames[j] == page[k])
                    {
                        dist = k - i;
                        break;
                    }
                }
                if (dist == 0)
                {
                    index = j;
                    break;
                }
                if (dist > max_dist)
                {
                    max_dist = dist;
                    index = j;
                }
            }
            frames[index] = page[i];
            fault++;
        }
        for (j = 0; j < f_count; ++j)
            printf("%d\t", frames[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults (Optimal): %d\n", fault);
    printf("Total Page Hits (Optimal): %d\n", hit);
}


int main()
{
    int page[100];
    int p_count, f_count;
    printf("Enter the number of page references: ");
    scanf("%d", &p_count);
    printf("Enter the page reference string: ");
    for (int i = 0; i < p_count; i++)
        scanf("%d", &page[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &f_count);
    FIFO(page, p_count, f_count);
    LRU(page, p_count, f_count);
    Optimal(page, p_count, f_count);
    return 0;
}
