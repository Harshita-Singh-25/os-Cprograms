#include <stdio.h>

void fcfsScheduling(int processes[], int n, int burstTime[]) {
    int waitingTime[n], turnaroundTime[n], completionTime[n];
    waitingTime[0] = 0;
    completionTime[0] = burstTime[0];

    // Calculate completion time
    for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i-1] + burstTime[i];
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    // Print table
    printf("\nProcess\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], completionTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Calculate averages
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burstTime[] = {6, 3, 8, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    printf("FCFS CPU Scheduling\n");
    fcfsScheduling(processes, n, burstTime);

    return 0;
}
