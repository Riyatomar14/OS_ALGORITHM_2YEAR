#include<iostream>
using namespace std;

void total_waitingtime(int p[], int n, int b[], int wt[]) {
    wt[0] = 0;  // Waiting time for the first process is always 0
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + b[i - 1];
        cout << "Waiting time for process " << p[i] << ": " << wt[i] << endl;
    }
}

void total_turnaroundtime(int p[], int n, int b[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + b[i];
        cout << "Turnaround time for process " << p[i] << ": " << tat[i] << endl;
    }
}

void avgtime(int p[], int n, int b[]) {
    int tat[n], wt[n];
    int totalwt = 0, totattat = 0;
    
    total_waitingtime(p, n, b, wt);
    total_turnaroundtime(p, n, b, wt, tat);
    
    for (int i = 0; i < n; i++) {
        totalwt += wt[i];
        totattat += tat[i];
    }
    
    cout << "Average waiting time: " << (float)totalwt / n << endl;
    cout << "Average turnaround time: " << (float)totattat / n << endl;
}

int main() {
    int p[] = {1, 2, 3};  
    int b[] = {4, 6, 12}; 
    int n = sizeof(p) / sizeof(p[0]); 
    
    avgtime(p, n, b);
    
    return 0;
}
