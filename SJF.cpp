#include <iostream>
using namespace std;

int main() {
    int n, bt[20], wt[20], tat[20];
    int avWt = 0, avTat = 0, i, j;

    cout << "Enter the number of processes (maximum 20): ";
    cin >> n;

    cout << "\nEnter the burst time for each process:\n";
    for (i = 0; i < n; i++) {
        cout << "P[" << i+1 << "]: ";
        cin >> bt[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    
    wt[0] = 0; 
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";


    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avWt += wt[i];
        avTat += tat[i];

        cout << "P[" << i+1 << "]\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    avWt /= n;
    avTat /= n;

    cout << "\nAverage Waiting Time: " << avWt;
    cout << "\nAverage Turnaround Time: " << avTat;

    return 0;
}
