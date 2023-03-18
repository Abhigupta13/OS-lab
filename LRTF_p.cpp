#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
struct Process { 
 int pid, bt, art, ct, tat, wt;
}; 
bool compare(Process& p1, Process& p2) { 
 return p1.bt < p2.bt; 
} 
void findWaitingTime(vector<Process>& processes) { 
 int n = processes.size(); 
 int remaining_bt[n]; 
 for (int i = 0; i < n; i++) { 
 remaining_bt[i] = processes[i].bt; 
 } 
 int t = 0; 
 int complete = 0; 
 while (complete != n) { 
 int max_bt = -1, max_i; 
 for (int i = 0; i < n; i++) { 
 if (processes[i].art <= t && remaining_bt[i] > max_bt) { 
 max_bt = remaining_bt[i]; 
 max_i = i; 
 } 
 } 
 if (max_bt == -1) { 
 t++; 
 continue; 
 } 
 remaining_bt[max_i]--; 
 t++; 
 if (remaining_bt[max_i] == 0) { 
 complete++; 
 processes[max_i].ct = t; 
 processes[max_i].tat = processes[max_i].ct - processes[max_i].art; 
 processes[max_i].wt = processes[max_i].tat - processes[max_i].bt; 
 } 
 } 
} 
void printProcesses(vector<Process>& processes) { 
 cout << "Process ID\tBurst Time\tArrival Time\tCompletion Time\tTurn Around Time\tWaiting Time\n"; 
 for (auto& p : processes) { 
 cout <<"   "<< p.pid << "\t\t" << p.bt << "\t\t" << p.art << "\t\t" << p.ct << "\t\t" << p.tat << "\t\t" 
<< p.wt << endl; 
 } 
} 
int main() { 
 int n; 
 cout << "Enter the number of processes: "; 
 cin >> n; 
 vector<Process> processes(n); 
 for (int i = 0; i < n; i++) { 
 cout << "Enter process " << i + 1 << " burst time and arrival time: "; 
 cin >> processes[i].bt >> processes[i].art; 
 processes[i].pid = i + 1; 
 } 
 sort(processes.begin(), processes.end(), compare); 
 findWaitingTime(processes); 
 double avg_tat = 0, avg_wt = 0; 
 for (auto& p : processes) { 
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
