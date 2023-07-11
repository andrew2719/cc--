#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mpi;
typedef set<int> seti;

int dfs(vector<string> &gr, int i, int j, int n, vector<vector<int>> &dp){
    if(i<0 || i>=n || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res = 0;
    if(gr[i][j]=='P') res++;
    
    int temp = 0;
    
    temp = max(temp,dfs(gr,i-2,j+1,n,dp));
    temp = max(temp,dfs(gr,i-1,j+2,n,dp));
    temp = max(temp,dfs(gr,i+1,j+2,n,dp));
    temp = max(temp,dfs(gr,i+2,j+1,n,dp));
    
    return dp[i][j] = res+temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<string> gr(n);
        for(int i=0;i<n;i++){
            cin>>gr[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(gr[i][j] == 'K'){
                    ans = dfs(gr,i,j,n,dp);
                }
            }
        }
        // print the DP
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}