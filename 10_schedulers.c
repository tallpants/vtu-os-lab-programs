/*
 * Design, develop and execute a program in C/C++ to simulate the working of
 * shortest remaining time and round robin scheduling algorithms. Experiment
 * with different time quantums for the round robin algorithms. In all cases,
 * determine the average turn-around time. The input can be read from keyboard
 * or from a file.
 */

#include <stdio.h>

void shortest_job_first(void) {
    int number_of_processes;
    int arrival_time[10];
    int burst_time[10];
    int burst_time_copy[10];
    int finished_count = 0;
    int time_taken = 0;
    int end_time;
    int smallest;           // Variable to index process with smallest burst time
    int i;                  // Loop index variable

    float total_waiting_time = 0.0;
    float total_turn_around_time = 0.0;

    printf("How many processes: ");
    scanf("%d", &number_of_processes);

    printf("Arrival times of processes: ");
    for (i = 0; i < number_of_processes; i++) {
        scanf("%d", &arrival_time[i]);
    }

    printf("Burst times of processes:   ");
    for (i = 0; i < number_of_processes; i++) {
        scanf("%d", &burst_time[i]);
        burst_time_copy[i] = burst_time[i];
    }

    burst_time[9] = 9999;

    for (time_taken = 0; finished_count != number_of_processes; time_taken++) {
        smallest = 9;

        for (i = 0; i < number_of_processes; i++) {
            // arrival_time[i] <= time_taken --> Checking if the process has arrived yet or not.
            // burst_time[i] < burst_time[smallest] --> Trying to find the process with smallest burst.
            // burst_time[i] > 0 --> If burst_time[i] = 0, then process i has already finished.
            if (arrival_time[i] <= time_taken && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }

        burst_time[smallest]--;

        if (burst_time[smallest] == 0) {
            finished_count++;
            end_time = time_taken + 1;
            total_waiting_time += end_time - arrival_time[smallest] - burst_time_copy[smallest];
            total_turn_around_time += end_time - arrival_time[smallest];
        }
    }

    printf("Average waiting time: %.2f\n", total_waiting_time / number_of_processes);
    printf("Average turn around time: %.2f\n", total_turn_around_time / number_of_processes);
}

void round_robin(void) {
    int number_of_processes;
    int burst_time[10];
    int burst_time_copy[10];
    int time_quantum;
    int finished_count = 0;
    int sum_of_time_quantums = 0;
    int waiting_time[10];
    int total_waiting_time = 0;
    int turn_around_time[10];
    int total_turn_around_time = 0;

    float average_waiting_time;
    float average_turn_around_time;

    int i;      // Loop index variable
    int temp;   // Temporary variable

    printf("Number of processes: ");
    scanf("%d", &number_of_processes);

    printf("Burst time of processes: ");
    for (i = 0; i < number_of_processes; i++) {
        scanf("%d", &burst_time[i]);
        burst_time_copy[i] = burst_time[i];
    }

    printf("Time quantum: ");
    scanf("%d", &time_quantum);

    while (1) {

        finished_count = 0;

        for (i = 0; i < number_of_processes; i++) {
            temp = time_quantum;
            if (burst_time_copy[i] == 0) {
                finished_count++;
                continue;
            }

            if (burst_time_copy[i] > time_quantum)
                burst_time_copy[i] -= time_quantum;
            else if (burst_time_copy[i] >= 0) {
                temp = burst_time_copy[i];
                burst_time_copy[i] = 0;
            }

            sum_of_time_quantums += temp;
            turn_around_time[i] = sum_of_time_quantums;
        }

        if (finished_count == number_of_processes) break;
    }

    for (i = 0; i < number_of_processes; i++) {
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
    }

    average_waiting_time = (float) total_waiting_time / number_of_processes;
    average_turn_around_time = (float) total_turn_around_time / number_of_processes;

    printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    printf("=======\t==========\t============\t=================\n");

    for (i = 0; i < number_of_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("\nAverage waiting time: %.2f", average_waiting_time);
    printf("\nAverage turn around time: %.2f\n", average_turn_around_time);
}

int main(void) {
    printf("1. Shortest job first\n");
    printf("2. Round robin\n");
    printf("> ");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            shortest_job_first();
            break;
        case 2:
            round_robin();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
