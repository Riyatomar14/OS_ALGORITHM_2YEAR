#include <iostream>
using namespace std;

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processes; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processes; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes];
    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processes; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int processes = sizeof(processSize) / sizeof(processSize[0]);

    cout << "Choose Allocation Strategy:\n";
    cout << "1. First Fit\n";
    cout << "2. Best Fit\n";
    cout << "3. Worst Fit\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            firstFit(blockSize, blocks, processSize, processes);
            break;
        case 2:
            bestFit(blockSize, blocks, processSize, processes);
            break;
        case 3:
            worstFit(blockSize, blocks, processSize, processes);
            break;
        default:
            cout << "Invalid choice!";
    }

    return 0;
}
