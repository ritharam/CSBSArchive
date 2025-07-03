#include <stdio.h>
#include <stdlib.h>

// Function to calculate total head movement using SCAN algorithm
int calculateSCAN(int *requests, int n, int current, int direction) {
    int totalMovement = 0;
    int head = current;
    int start = 0, end = 199; // Assuming disk range is from 0 to 199

    // Sort the requests array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Find the index of the current position in the sorted requests array
    int index;
    for (index = 0; index < n; index++) {
        if (requests[index] >= current) {
            break;
        }
    }

    // Traverse in the given direction until the end of the requests
    if (direction == 1) {
        for (int i = index; i < n; i++) {
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
        totalMovement += end - head;
        head = end;
        // Traverse back in the opposite direction to the start
        for (int i = index - 1; i > 0; i--) {
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
    }
    // Traverse in the opposite direction until the start of the requests
    else {
        for (int i = index - 1; i >= 0; i--) {
            totalMovement += abs(requests[i] - head);
            printf(" %d - %d ", requests[i],head);
            head = requests[i];
        }
        totalMovement += head - start;
        head = start;
        // Traverse back in the opposite direction to the end
        for (int i = index; i < n; i++) {
            totalMovement += abs(requests[i] - head);
            printf(" %d - %d ", requests[i],head);
            head = requests[i];
        }
    }

    return totalMovement;
}

int main() {
    int n;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the request order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    int current;
    printf("Enter the current position of the disk head: ");
    scanf("%d", &current);

    // Calculate total head movement using SCAN algorithm
    int totalMovementSCAN = calculateSCAN(requests, n, current, 1); // Assuming direction towards end
    printf("Total head movement using SCAN: %d\n", totalMovementSCAN);

    return 0;
}
