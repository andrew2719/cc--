// round robin scheduling

#include<bits/stdc++.h>
using namespace std;

class Process{
public:
    int pid;
    int burst_time;
    int arrival_time;
    Process(int pid, int art, int bt){
        this->pid = pid;
        this->burst_time = bt;
        this->arrival_time = art;
    }

};


bool in_queue(queue<Process> ready_queue, Process p){
    while(!ready_queue.empty()){
        if(ready_queue.front().pid == p.pid){
            return true;
        }
        ready_queue.pop();
    }
    return false;
}

int main(){
    vector<Process> processes = {
        Process(1,0,5),
        Process(2,1,3),
        Process(3,2,8),
        Process(4,3,6)
    };

    sort(processes.begin(),processes.end(),[&](Process a, Process b){
        return a.arrival_time < b.arrival_time;
    });

    // print the processes
    cout<<"Processes: "<<endl;
    for(auto p: processes){
        cout<<"Process "<<p.pid<<" with arrival time "<<p.arrival_time<<" and burst time "<<p.burst_time<<endl;
    }

    queue<Process> ready_queue;
    int time_quantum = 2;
    int time = 0;
    int n = processes.size();
    
    ready_queue.push(processes[0]);
    time+=time_quantum;


    // | Process | Arrival Time | Burst Time |
    // |---------|--------------|------------|
    // |    1    |       0      |       5     |
    // |    2    |       1      |      3     |
    // |    3    |       2      |      8     |
    // |    4    |       3      |      6     |

    vector<int> done_processes;
    while(done_processes.size() != n){
        // find all the processes that are less than the present time and push them to the ready queue except the ones that are already in the ready queue
        for(int i=0;i<n;i++){
            if(processes[i].arrival_time <= time && !in_queue(ready_queue,processes[i]) && find(done_processes.begin(),done_processes.end(),processes[i].pid) == done_processes.end()){
                ready_queue.push(processes[i]);
            }
        }

        Process &p = ready_queue.front();
        if(p.burst_time > 0){
            p.burst_time = p.burst_time - time_quantum;
            
            time+=time_quantum;
            bool finished = false;
            if(p.burst_time <= 0){
                cout<<"Process "<<p.pid<<" completed at time "<<time+p.burst_time<<endl;
                time = time + p.burst_time;
                done_processes.push_back(p.pid);
                finished = true;
            }
            ready_queue.pop();
            if(!finished)
            ready_queue.push(p);
        }
        else{
            ready_queue.pop();
            
        }
    }
}



