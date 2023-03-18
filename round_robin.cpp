#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Process
{
    int pid, bt, art, ct, tat, wt;
};
void findWaitingTime(vector<Process> &processes, int quantum)
{
    int n = processes.size();
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = processes[i].bt;
    }
    int t = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (rem_bt[i] <= quantum)
        {
            t += rem_bt[i];
            processes[i].ct = t;
            rem_bt[i] = 0;
        }
        else
        {
            t += quantum;
            rem_bt[i] -= quantum;
        }
        for (int j = 0; j < n; j++)
        {
            if (processes[j].art <= t && rem_bt[j] > 0)
            {
                q.push(j);
            }
        }
        if (rem_bt[i] > 0)
        {
            q.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        processes[i].tat = processes[i].ct - processes[i].art;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}
void printProcesses(vector<Process> &processes)
{
    cout << "Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for (auto &p : processes)
    {
        cout << "   "<<p.pid << "\t\t" << p.bt << "\t\t" << p.art << "\t\t" << p.ct << "\t\t\t" << p.tat << "\t\t"
             << p.wt << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter process " << i + 1 << " burst time and arrival time: ";
        cin >> processes[i].bt >> processes[i].art;
        processes[i].pid = i + 1;
    }
    int quantum = 3;
    findWaitingTime(processes, quantum);
    double avg_tat = 0, avg_wt = 0;
    for (auto &p : processes)
    {
        avg_tat += p.tat;
        avg_wt += p.wt;
    }
    avg_tat /= n;
    avg_wt /= n;
    printProcesses(processes);
    cout << "Average turn around time: " << avg_tat << endl;
    cout << "Average waiting time: " << avg_wt << endl;
    return 0;
}