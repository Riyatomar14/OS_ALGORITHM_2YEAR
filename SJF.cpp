#include <iostream>
using namespace std;

void bubbleSort(int p[], int b[], int a[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) { 
                swap(b[j], b[j + 1]);// Swap burst times
                swap(p[j], p[j + 1]);// Swap process numbers to match burst times
                swap(a[j], a[j + 1]);// Swap arrival times 
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
    cout << endl;
}

void total_waitingtime(int p[], int n, int b[], int a[], int wt[]) {
    int current_time = 0;
    wt[0] = 0;  
    for (int i = 1; i < n; i++) {
        current_time += b[i - 1];
        wt[i] = current_time - a[i];  
        if (wt[i] < 0) {  
            wt[i] = 0;
            current_time = a[i];  
        }
        cout << "Waiting time for process " << p[i] << ": " << wt[i] << endl;
    }
}

void total_turnaroundtime(int p[], int n, int b[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + b[i]; 
        cout << "Turnaround time for process " << p[i] << ": " << tat[i] << endl;
    }
}

void avgtime(int p[], int n, int b[], int a[]) {
    int tat[n], wt[n];
    int totalwt = 0, totalTat = 0;
    
    total_waitingtime(p, n, b, a, wt);
    total_turnaroundtime(p, n, b, wt, tat);
    
    for (int i = 0; i < n; i++) {
        totalwt += wt[i];
        totalTat += tat[i];
    }
    
    cout << "Average waiting time: " << (float)totalwt / n << endl;
    cout << "Average turnaround time: " << (float)totalTat / n << endl;
}

int main() {
    int p[] = {1, 2, 3, 4, 5, 6, 7};  // Process IDs
    int b[] = {6, 3, 4, 2, 1, 5, 2};  // Burst times
    int a[] = {0, 0, 1, 2, 3, 4, 5};  // Arrival times
    int n = sizeof(p) / sizeof(p[0]); 
    
    bubbleSort(p, b, a, n);  // Sort processes by burst times
    
    cout << "Processes sorted according to burst time:\n";
    cout << "Process IDs: ";
    printArray(p, n);  // Print sorted process IDs
    cout << "Burst times: ";
    printArray(b, n);  // Print sorted burst times
    cout << "Arrival times: ";
    printArray(a, n);  // Print arrival times
    cout << endl;
    
    avgtime(p, n, b, a);  // Calculate and print average times
    
    return 0;
}
