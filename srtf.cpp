#include <iostream>
using namespace std;

// Define your own maximum integer constant
const int MY_INT_MAX = 2147483647; // This is 2^31 - 1, typical max value for int in many systems

void sjfPreemptive(int p[], int n, int b[], int a[]) {
    int remaining_burst[n];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = b[i];
    }
    
    int tat[n], wt[n];
    int totalwt = 0, totalTat = 0;
    int current_time = 0;
    int completed = 0;
    int min_remaining_time, shortest = 0;
    bool check = false;
    
    // Initialize waiting time and turnaround time arrays
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }
    
    while (completed < n) {
        min_remaining_time = MY_INT_MAX;
        check = false;
        
        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++) {
            if (a[i] <= current_time && remaining_burst[i] < min_remaining_time && remaining_burst[i] > 0) {
                min_remaining_time = remaining_burst[i];
                shortest = i;
                check = true;
            }
        }
        
        if (!check) {
            current_time++;
            continue;
        }
        
        remaining_burst[shortest]--;
        
        if (remaining_burst[shortest] == 0) {
            completed++;
            int finish_time = current_time + 1;
            tat[shortest] = finish_time - a[shortest];
            wt[shortest] = tat[shortest] - b[shortest];
            
            totalwt += wt[shortest];
            totalTat += tat[shortest];
        }
        
        current_time++;
    }
    
    // Output results
    for (int i = 0; i < n; i++) {
        cout << "Waiting time for process " << p[i] << ": " << wt[i] << endl;
        cout << "Turnaround time for process " << p[i] << ": " << tat[i] << endl;
    }
    
    cout << "Average waiting time: " << (float)totalwt / n << endl;
    cout << "Average turnaround time: " << (float)totalTat / n << endl;
}

int main() {
    int p[] = {1, 2, 3, 4, 5, 6};  // Process IDs
    int b[] = {4, 2, 3, 5, 6, 1};  // Burst times
    int a[] = {0, 1, 2, 3, 4, 5};  // Arrival times
    int n = sizeof(p) / sizeof(p[0]);
    
    sjfPreemptive(p, n, b, a);
    
    return 0;
}
