#include<bits/stdc++.h>
using namespace std;

// dfs
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, storeDfs);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    vector<int> vis(n+1, 0);
    vector<int> storeDfs;
    dfs(src, vis, adj, storeDfs);
    for(int i=0; i<storeDfs.size(); i++){
        cout<<storeDfs[i]<<" ";
    }
    return 0;
}
