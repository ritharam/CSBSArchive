#include <stdio.h>
#include <math.h>

#define MAX_PAGES 1000

// Page table entry structure
typedef struct {
    int valid;
    int frame_number;
} PageTableEntry;

// Page table array
PageTableEntry page_table[MAX_PAGES];

int main() {
    int logical_address, page_size, num_pages, num_frames, page_number, offset;
    int physical_address;

    // Get range of physical and logical address
    printf("Enter the range of physical memory (in bytes): ");
    scanf("%d", &num_frames); // Number of frames
    printf("Enter the range of logical memory (in bytes): ");
    scanf("%d", &num_pages); // Number of pages

    // Get page size
    printf("Enter the page size (in bytes): ");
    scanf("%d", &page_size);

    // Construct page table by mapping logical address to physical address
    for (int i = 0; i < num_pages; i++) {
        page_table[i].valid = 1;
        page_table[i].frame_number = i; // For simplicity, mapping each page directly to a frame
    }

    // Get the page number of data
    printf("Enter the logical address (in bytes): ");
    scanf("%d", &logical_address);

    // Calculate page number and offset
    page_number = logical_address / page_size;
    offset = logical_address % page_size;

    // Search page number in page table and locate the base address
    if (page_number >= 0 && page_number < num_pages && page_table[page_number].valid) {
        // Calculate physical address
        physical_address = (page_table[page_number].frame_number * page_size) + offset;

        // Print the physical address
        printf("Physical Address: %d\n", physical_address);
    } else {
        printf("Page fault: Invalid page number\n");
    }

    return 0;
}
