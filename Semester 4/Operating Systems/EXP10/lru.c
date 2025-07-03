#include <stdio.h>

#define MAX_FRAMES 100

int main()
{
    int page_reference[MAX_FRAMES]; // to store the page reference string
    int frames[MAX_FRAMES];         // to store the frames
    int frame_age[MAX_FRAMES];      // to store the age of each frame
    int page_count, frame_count, page_fault = 0, page_hit = 0;
    int i, j, k;

    printf("Enter the number of page references: ");
    scanf("%d", &page_count);

    printf("Enter the page reference string: ");
    for (i = 0; i < page_count; i++)
        scanf("%d", &page_reference[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    // Initialize frames and frame_age
    for (i = 0; i < frame_count; i++)
    {
        frames[i] = -1;   // -1 indicates an empty frame
        frame_age[i] = page_count + 1; // Initialize age to a large value
    }

    printf("\nPage Reference\t Page Frames\n");
    for (i = 0; i < page_count; i++)
    {
        printf("%d\t\t", page_reference[i]);

        // Check if page already exists in frame
        int page_found = 0;
        for (j = 0; j < frame_count; ++j)
        {
            if (frames[j] == page_reference[i])
            {
                page_found = 1;
                page_hit++;
                frame_age[j] = 0; // Reset age to 0
                break;
            }
        }

        // Page not found in frames
        if (!page_found)
        {
            int oldest_page_index = 0;
            int max_age = frame_age[0];
            for (j = 1; j < frame_count; ++j)
            {
                if (frame_age[j] > max_age)
                {
                    max_age = frame_age[j];
                    oldest_page_index = j;
                }
            }

            frames[oldest_page_index] = page_reference[i];
            frame_age[oldest_page_index] = 0; // Reset age to 0
            page_fault++;
        }

        // Increment age of all frames
        for (k = 0; k < frame_count; ++k)
        {
            if (frames[k] != -1)
                frame_age[k]++;
        }

        // Print current page frames
        for (j = 0; j < frame_count; ++j)
            printf("%d\t", frames[j]);

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_fault);
    printf("Total Page Hits: %d\n", page_hit);

    return 0;
}
