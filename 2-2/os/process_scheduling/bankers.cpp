// page replacement algorithm: bankers

#include<bits/stdc++.h>
using namespace std;

struct Process{
    int p_id;
    int A, B, C;
};

int main(){
    int n;
    cin>>n;
    vector<Process> process(n);

    for(int i=0; i<n; i++){
        cin>>process[i].p_id>>process[i].A>>process[i].B>>process[i].C;
    }
}