#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 100

int main() {
    int page_reference[MAX_FRAMES]; // to store the page reference string
    int frames[MAX_FRAMES]; // to store the frames
    int page_count, frame_count, page_fault = 0, page_hit = 0;
    int i, j, k;

    printf("Enter the number of page references: ");
    scanf("%d", &page_count);

    printf("Enter the page reference string: ");
    for (i = 0; i < page_count; ++i)
        scanf("%d", &page_reference[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    // Initialize frames
    for (i = 0; i < frame_count; ++i)
        frames[i] = -1; // -1 indicates an empty frame

    printf("\nPage Reference\t Page Frames\n");
    for (i = 0; i < page_count; ++i) {
        printf("%d\t\t", page_reference[i]);

        // Check if page already exists in frame
        int page_found = 0;
        for (j = 0; j < frame_count; ++j) {
            if (frames[j] == page_reference[i]) {
                page_found = 1;
                page_hit++;
                break;
            }
        }

        // Page not found in frames
        if (!page_found) {
            int farthest_page_index = -1;
            int farthest_page_distance = INT_MIN;
            for (j = 0; j < frame_count; ++j) {
                int future_distance = INT_MAX;
                for (k = i + 1; k < page_count; ++k) {
                    if (frames[j] == page_reference[k]) {
                        future_distance = k - i;
                        break;
                    }
                }
                if (future_distance > farthest_page_distance) {
                    farthest_page_distance = future_distance;
                    farthest_page_index = j;
                }
            }

            frames[farthest_page_index] = page_reference[i];
            page_fault++;
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
