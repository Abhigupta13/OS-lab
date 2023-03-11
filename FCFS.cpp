
#include<iostream>
using namespace std;
#include <string.h> 

// Process class to store process attributes
class Process {
public:
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

// Function to calculate average turn around time and average waiting time
void calculate_avg_times(Process processes[], int n) {
    int total_turnaround_time = 0, total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }
    float avg_turnaround_time = (float)total_turnaround_time / n;
    float avg_waiting_time = (float)total_waiting_time / n;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process processes[n];
    cout << "Enter the arrival time and burst time of each process:" << endl;
    for (int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        cin >> processes[i].arrival_time >> processes[i].burst_time;
    }

    // FCFS Scheduling Algorithm
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
    }

    // Calculate average turn around time and average waiting time
    calculate_avg_times(processes, n);

    return 0;
}
