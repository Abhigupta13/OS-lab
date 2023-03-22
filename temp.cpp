#include <bits/stdc++.h>
#include <pthread.h>
#include <stdbool.h>
using namespace std;
bool want[2] = {false, false};
int turn = 0;
int critical_section = 0;

void enter_critical_section(int process_id) {
    want[process_id] = true;
    turn = 1 - process_id;
    while (want[1 - process_id] && turn == 1 - process_id);
    // critical section
    cout<<"Process entered critical section: "<< process_id<<endl;
    critical_section++;
    cout<<"Critical section count: "<< critical_section<<endl;
    // end of critical section
    want[process_id] = false;
}

void* process1(void* arg) {
    enter_critical_section(0);
    return NULL;
}

void* process2(void* arg) {
    enter_critical_section(1);
    return NULL;
}

int main() {
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, process1, NULL);
    pthread_create(&threads[1], NULL, process2, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    cout<<"Final critical section count: "<< critical_section<<endl;
    return 0;
}