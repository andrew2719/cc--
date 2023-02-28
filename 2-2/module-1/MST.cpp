#include<bits/stdc++.h>

using namespace std;

bool check_common_in_both_vectors(vector<int> v1, vector<int> v2){
    unordered_set<int> s(v1.begin(), v1.end()); // use set to store elements of v1
    for(int i=0; i<v2.size(); i++){
        if(s.find(v2[i]) != s.end()){ // check if element in v2 is in set s
            return true;
        }
    }
    return false;
}


int main(){
    // -1 means no edge
    vector<vector<int>> adj = {{0 ,-1 ,72 ,50 ,90 ,35},
                                {-1 ,0 ,71 ,70 ,73 ,75},
                                {72 ,71 ,0 ,-1 ,77 ,90},
                                {50 ,70 ,-1 ,0 ,60 ,40},
                                {90 ,73 ,77 ,60 ,0 ,80},
                                {35 ,75 ,90 ,40 ,80 ,0}};

    // sort the edges in ascending order of their weights
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<adj.size(); i++){
        for(int j=i+1; j<adj.size(); j++){
            if(adj[i][j] != -1){
                edges.push_back({adj[i][j], {i, j}});
            }
        }
    }
    sort(edges.begin(), edges.end());

    // create a vector for masking
    vector<vector<int>> mask;

    // inisialize with empty vector {}
    for(int i=0; i<adj.size(); i++){
        vector<int> temp;
        mask.push_back(temp);
    }

    map<pair<int,int>,int> mst; // MST (min spanning tree map with (<vertex1,vertex2>,weight) - edge)
    int weight = 0;
    for(auto edge: edges){
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        mask[u].push_back(v);
        mask[v].push_back(u);

        if(!check_common_in_both_vectors(mask[u], mask[v])){
            mst[{u,v}] = w; // if intersection is 0 then add the edge to mst that means it cannot form a cycle
            weight += w;
        }
        
    }
    // print the mst
    for(auto edge: mst){
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
    }

    // print weight

    cout << "Weight of MST: " << weight << endl;
    return 0;

}