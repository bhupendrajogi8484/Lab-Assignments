#include "stdio.h"
#include "string.h"
#include "pthread.h"
#include "semaphore.h"
#include "stdlib.h"
#include "unistd.h"

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    getchar(); // Replaces getch() to pause the program
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);
    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the available resources\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("Process\t Allocation\t Max\t Available\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t ", i + 1);
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0) {
            for (j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void cal() {
    int finish[100], safe[100], temp, flag = 1, k, c1 = 0;
    int i, j, index = 0;

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Calculate Need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\n");

    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            int canFinish = 1;
            for (j = 0; j < r; j++) {
                if (finish[i] == 0 && need[i][j] > avail[j]) {
                    canFinish = 0;
                    break;
                }
            }
            if (canFinish) {
                for (k = 0; k < r; k++) {
                    avail[k] += alloc[i][k];
                }
                safe[index++] = i;
                finish[i] = 1;
                flag = 1;
            }
        }
    }

    // Check if all processes can finish
    for (i = 0; i < n; i++) {
        if (finish[i] == 1) {
            c1++;
        }
    }

    if (c1 == n) {
        printf("\nThe system is in a safe state.\nSafe Sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d ", safe[i]);
        }
        printf("\n");
    } else {
        printf("\nProcesses are in deadlock.\nSystem is in an unsafe state.\n");
    }
}
