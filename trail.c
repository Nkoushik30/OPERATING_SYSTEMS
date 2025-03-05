#include<stdio.h>

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg = 0, tatavg = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter the burst time for process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
    }

    for(i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);

    return 0;
}
