#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

void total_waitingtime(int p[], int n, int b[], int wt[]) {
    wt[0] = 0;  
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
    int totalwt = 0, totalTat = 0;
    
    total_waitingtime(p, n, b, wt);
    total_turnaroundtime(p, n, b, wt, tat);
    
    for (int i = 0; i < n; i++) {
        totalwt += wt[i];
        totalTat += tat[i];
    }
    
    cout << "Average waiting time: " << (float)totalwt / n << endl;
    cout << "Average turnaround time: " << (float)totalTat / n << endl;
}

int main() {
    int p[] = {1, 2, 3, 4};  
    int b[] = {4, 7, 2, 9}; 
    int n = sizeof(p) / sizeof(p[0]);
    
    bubbleSort(b, n);
    cout<< "sort according to burst time";
    printArray(b,n);
    cout<< endl;
    
    avgtime(p, n, b);
    
    return 0;
}
