#include <iostream>
#include <queue>

using namespace std;

// Struct representing a process
struct Process {
    int id;
    int priority;
    int time;
};

// Comparator function for priority queue
struct CompareProcess {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority < p2.priority;
    }
};

// Function to simulate the interrupt handling process
void handleInterrupt(priority_queue<Process, vector<Process>, CompareProcess>& pq) {
    // Check if there are any processes in the queue
    if (!pq.empty()) {
        // Get the highest priority process from the queue
        Process currProcess = pq.top();
        pq.pop();
        
        // Print out information about the process
        cout << "Handling device interrupt with id " << currProcess.id << " and priority " << currProcess.priority << endl;
        cout << "Time required to handle device interrupt: " << currProcess.time << " seconds" << endl;
        
        // Simulate handling the process
        for (int i = 1; i <= currProcess.time; i++) {
            cout << "Processing... (" << i << "/" << currProcess.time << ")" << endl;
        }
        
        cout << "device interrupt with id " << currProcess.id << " and priority " << currProcess.priority << " handled successfully!" << endl;
    }
    else {
        cout << "No device interrupts to handle" << endl;
    }
}

int main() {
    // Create a priority queue of processes
    priority_queue<Process, vector<Process>, CompareProcess> pq;
    
    // Add some processes to the queue
    pq.push({1, 2, 5});
    pq.push({2, 1, 3});
    pq.push({3, 3, 4});
    
    while(!pq.empty()) {
        handleInterrupt(pq);
    }
    
    return 0;
}
