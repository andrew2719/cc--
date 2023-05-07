

#include<bits/stdc++.h>
using namespace std;

void s_subst(vector<int> a,int k,int sum,int i,vector<int> &x){
    if(sum==k){
        for(int j=0;j<x.size();j++){
            cout<<x[j]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i==a.size()){
        return;
    }
    if(sum+a[i]<=k){
        x.push_back(a[i]);
        s_subst(a,k,sum+a[i],i+1,x);
        x.pop_back();
    }
    s_subst(a,k,sum,i+1,x);
}


int main(){
    int k;
    int n;
    cin>>n;
    cin>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> x;
    s_subst(a,k,0,0,x);
    return 0;

}