#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        int k;
        cin>>k;
        int arr[m][n];
        //map<pair<int,int>,int> mp; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                //mp[{i,arr[i][j]}]+=1;
            }
        }
        int ans = INT_MAX;
        map<int,int> mp2; // {box size, count}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                mp2[arr[i][j]]+=1;
                if(mp2[arr[i][j]]>=k){
                    ans = min(ans,i+1);
                    break;
                }

            }

        }
        if(ans==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}