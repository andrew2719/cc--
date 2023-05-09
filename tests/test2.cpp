// finding cycle in a graph
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n,0);
    bool cycle=false;
    function<void(int)> dfs=[&](int u){
        vis[u]=1;
        for(int v:adj[u]){
            if(vis[v]==1){
                cycle=true;
                return;
            }
            if(vis[v]==0){
                dfs(v);
            }
        }
        vis[u]=2;
    };
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    if(cycle){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}