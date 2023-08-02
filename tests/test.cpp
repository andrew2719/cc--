#include<bits/stdc++.h>
using namespace std;

int recursion_by_months(vector<pair<int,int>> &a,int n, int w, int I, int month){
  int total = 0;
  for(int i=0;i<n;i++){
    a[i].first+=a[i].second;
    if(a[i].first>=I){
      total+=a[i].first;
    }
  }
  if(total>=w){
    return month;
  }
  else{
    return recursion_by_months(a,n,w,I,month+1);
  }
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,w,I;
    cin>>n>>w>>I;
    vector<pair<int,int>> a(n);
    int initial = 0;
    for(int i=0;i<n;i++){
      cin>>a[i].first>>a[i].second;
      initial += a[i].first;
    }
    if(initial>=w){
      cout<<0<<endl;
    }
    else{
      cout<<recursion_by_months(a,n,w,I,1)<<endl;
    }
  }
}