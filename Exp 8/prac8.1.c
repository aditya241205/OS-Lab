#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int remainingBurst;
    int completion;
    int waiting;
    int turnaround;
};

int main() {
    int n, time = 0, completed = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int isCompleted[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Priority (lower number = higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].remainingBurst = p[i].burst;  // Initialize remaining burst time
        isCompleted[i] = 0;
    }

    while (completed < n) {
        int highest = -1;
        int minPriority = 999999;

        // Look for the process with highest priority (preemptive)
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && isCompleted[i] == 0 && p[i].remainingBurst > 0) {
                if (p[i].priority < minPriority) {
                    highest = i;
                    minPriority = p[i].priority;
                }
            }
        }

        if (highest != -1) {
            p[highest].remainingBurst--;  // Execute the process for 1 unit of time
            time++;

            // If the process has finished execution
            if (p[highest].remainingBurst == 0) {
                p[highest].completion = time;
                p[highest].turnaround = p[highest].completion - p[highest].arrival;
                p[highest].waiting = p[highest].turnaround - p[highest].burst;

                isCompleted[highest] = 1;
                completed++;
            }
        } else {
            time++;  // If no process can run, just increment time
        }
    }

    float totalWT = 0, totalTAT = 0;

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].priority,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
