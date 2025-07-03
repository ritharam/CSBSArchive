#include <stdio.h>

void main() {
    int instance[5], availability[5], allocated[10][5], need[10][5], MAX[10][5], P[10], op[100];
    int no_of_resources, process, i, j, k = 0, cnt = 0;

    printf("\nEnter the number of resources: ");
    scanf("%d", &no_of_resources);

    printf("\nEnter the max instances of each resource:\n");
    for (i = 0; i < no_of_resources; i++) {
        printf("%c= ", (i + 97));
        scanf("%d", &instance[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &process);

    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < process; i++) {
        P[i] = i;
        printf("P[%d]  ", P[i]);
        for (j = 0; j < no_of_resources; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("\nEnter the MAX matrix:\n");
    for (i = 0; i < process; i++) {
        printf("P[%d]  ", i);
        for (j = 0; j < no_of_resources; j++) {
            scanf("%d", &MAX[i][j]);
        }
    }

    for (i = 0; i < no_of_resources; i++) {
        availability[i] = instance[i];
        for (j = 0; j < process; j++) {
            availability[i] -= allocated[j][i];
        }
    }

    int safe = 0;
    while (k < process) {
        safe = 0;
        for (i = 0; i < process; i++) {
            if (P[i] != -1) {
                cnt = 0;
                for (j = 0; j < no_of_resources; j++) {
                    need[i][j] = MAX[i][j] - allocated[i][j];
                    if (need[i][j] <= availability[j])
                        cnt++;
                }
                if (cnt == no_of_resources) {
                    op[k++] = P[i];
                    for (j = 0; j < no_of_resources; j++)
                        availability[j] += allocated[i][j];
                    P[i] = -1;
                    safe = 1;
                }
            }
        }
        if (!safe) {
            printf("\nUnsafe State! Deadlock may occur.\n");
            break;
        }
    }

    if (safe) {
        printf("\nSafe sequence:");
        printf("\n<");
        for (i = 0; i < k; i++) {
            printf(" P[%d] ", op[i]);
        }
        printf(">");
    }

    getchar(); // To keep the console window open
}
