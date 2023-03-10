#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Process class to store process attributes
class Process {
public:
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

// Function to calculate average turn around time and average waiting time
void calculate_avg_times(vector<Process> processes) {
    int total_turnaround_time = 0, total_waiting_time = 0;
    for (int i = 0; i< processes.size(); i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }
    float avg_turnaround_time = (float)total_turnaround_time / processes.size();
    float avg_waiting_time = (float)total_waiting_time / processes.size();
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    cout << "Enter the arrival time and burst time of each process:" << endl;
    for (int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // SRTF Scheduling Algorithm
    int current_time = 0, completed_processes = 0;
    vector<Process> ready_queue;
    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                ready_queue.push_back(processes[i]);
            }
        }
        if (ready_queue.empty()) {
            current_time++;
            continue;
        }
        sort(ready_queue.begin(), ready_queue.end(), [](Process a, Process b) {
            return a.remaining_time < b.remaining_time;
        });
        Process& current_process = ready_queue.front();
        current_process.remaining_time--;
        current_time++;
        if (current_process.remaining_time == 0) {
            current_process.completion_time = current_time;
            completed_processes++;
            ready_queue.erase(ready_queue.begin());
        }
    }

    // Calculate average turn around time and average waiting time
    calculate_avg_times(processes);

    return 0;
}
