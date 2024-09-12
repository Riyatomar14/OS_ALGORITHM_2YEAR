#include<iostream>
using namespace std;

void total_waitingtime(int p[], int n, int b[], int a[], int wt[]) {
    int current_time = 0;
    wt[0] = 0;  // Waiting time for the first process is always 0 as it arrives first.
    
    for (int i = 1; i < n; i++) {
        current_time += b[i - 1];
        wt[i] = current_time - a[i];  // Waiting time = current time - arrival time
        if (wt[i] < 0) {  // If the waiting time is negative, it means the process arrived before the CPU finished the previous process
            wt[i] = 0;
            current_time = a[i];  
        }
        cout << "Waiting time for process " << p[i] << ": " << wt[i] << endl;
    }
}

void total_turnaroundtime(int p[], int n, int b[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + b[i];  // Turnaround time = waiting time + burst time
        cout << "Turnaround time for process " << p[i] << ": " << tat[i] << endl;
    }
}

void avgtime(int p[], int n, int b[], int a[]) {
    int tat[n], wt[n];
    int totalwt = 0, totattat = 0;
    
    total_waitingtime(p, n, b, a, wt);
    total_turnaroundtime(p, n, b, wt, tat);
    
    for (int i = 0; i < n; i++) {
        totalwt += wt[i];
        totattat += tat[i];
    }
    
    cout << "Average waiting time: " << (float)totalwt / n << endl;
    cout << "Average turnaround time: " << (float)totattat / n << endl;
}

int main() {
    int p[] = {1, 2, 3, 4, 5, 6};  // Process IDs
    int b[] = {4, 2, 3, 5, 6, 1}; // Burst times
    int a[] = {0, 1, 2, 3, 4, 5};  // Arrival times
    int n = sizeof(p) / sizeof(p[0]); 
    
    avgtime(p, n, b, a);
    
    return 0;
}

