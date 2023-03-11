#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void minimizeDFA(int N, int transition[][2]) {
    // Create an array to keep track of equivalent states
    bool equivalent[N][N];

    // Initialize the equivalent array to false
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            equivalent[i][j] = false;
        }
    }

    // Mark non-final and final states as distinct
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i < N/2 && j >= N/2) || (i >= N/2 && j < N/2)) {
                equivalent[i][j] = false;
            } else {
                equivalent[i][j] = true;
            }
        }
    }

    // Iteratively mark equivalent states
    bool changed = true;
    while (changed) {
        changed = false;

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (!equivalent[i][j]) {
                    bool eq = true;
                    for (int k = 0; k < 2; k++) {
                        int ti = transition[i][k];
                        int tj = transition[j][k];
                        if (!equivalent[ti][tj]) {
                            eq = false;
                            break;
                        }
                    }
                    if (eq) {
                        equivalent[i][j] = true;
                        changed = true;
                    }
                }
            }
        }
    }

    // Print the minimized DFA
    cout << "Minimized Transition Table:\n";
    cout << "State/Input | 0 | 1\n";
    cout << "-------------|---|---\n";
    for (int i = 0; i < N; i++) {
        if (!equivalent[i][0]) {
            continue;
        }
        cout << "     " << i << "      | " << transition[i][0] << " | " << transition[i][1] << endl;
        for (int j = i+1; j < N; j++) {
            if (equivalent[i][j]) {
                equivalent[i][j] = false;
            }
        }
    }
}


int main() {
    int N;
    cout << "Enter the number of states in the DFA: ";
    cin >> N;

    int transition[N][2];
    for (int i = 0; i < N; i++) {
        transition[i][0] = (i * 2) % N;
        transition[i][1] = (i * 2 + 1) % N;
    }
    cout << "Transition Table:\n";
    cout << "State/Input | 0 | 1\n";
    cout << "-------------|---|---\n";
    for (int i = 0; i < N; i++) {
        cout << "     " << i << "      | " << transition[i][0] << " | " << transition[i][1] << endl;
    }

    minimizeDFA(N, transition);

    return 0;
}
