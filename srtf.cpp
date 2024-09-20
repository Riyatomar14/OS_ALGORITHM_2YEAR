#include <iostream>
using namespace std;

int main() {
    int n, bt[20], at[20], wt[20], tat[20], rt[20];
    int time = 0, smallest, remain = 0, end, avWt = 0, avTat = 0;

    cout << "Enter the number of processes (maximum 20): ";
    cin >> n;

    cout << "\nEnter the arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << i+1 << "] Arrival Time: ";
        cin >> at[i];
        cout << "P[" << i+1 << "] Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "\nProcess\t\tWaiting Time\tTurnaround Time\n";
    rt[19] = 9999;
    
    while (remain != n) {
        smallest = 19;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < rt[smallest]) { 
                smallest = i;
            }
        }

        rt[smallest]--; 

        if (rt[smallest] == 0) { 
            remain++;
            end = time + 1;
            wt[smallest] = end - at[smallest] - bt[smallest]; 
            
            tat[smallest] = end - at[smallest];           
            avWt += wt[smallest];
            avTat += tat[smallest];

            cout << "P[" << smallest+1 << "]\t\t" << wt[smallest] << "\t\t" << tat[smallest] << endl;
        }
        time++; 
    }

    cout << "\nAverage Waiting Time: " << (float(avWt) / n);
    cout << "\nAverage Turnaround Time: " << (float(avTat) / n);

    return 0;
}
