#include <stdlib.h>
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};
int main() {
    int n = 4; // number of processes
    struct process p[] = {{1, 0, 5, 5, 0, 0},
                          {2, 1, 3, 3, 0, 0},
                          {3, 2, 3, 3, 0, 0},
                          {4, 4, 1, 1, 0, 0}};
    
    int current_time = 0;
    int completed = 0;
    int shortest = -1;
    int i, j;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    
    while (completed < n) {
        shortest = -1;
        for (i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0) {
                if (shortest == -1 || p[i].remaining_time < p[shortest].remaining_time) {
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            current_time++;
            continue;
        }
        p[shortest].remaining_time--;
        if (p[shortest].remaining_time == 0) {
            completed++;
            p[shortest].turnaround_time = current_time + 1 - p[shortest].arrival_time;
            p[shortest].waiting_time = p[shortest].turnaround_time - p[shortest].burst_time;
            total_waiting_time += p[shortest].waiting_time;
            total_turnaround_time += p[shortest].turnaround_time;
        }
        current_time++;
    }
    
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", total_waiting_time/n);
    printf("Average turnaround time: %.2f\n", total_turnaround_time/n);

    return 0;
}

