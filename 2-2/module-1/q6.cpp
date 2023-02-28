#include<bits/stdc++.h>
using namespace std;



void sort_array_with_deadline(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end(),[](vector<int> a,vector<int> b){
        return a[1]<b[1];
    });
}
auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    };
void Job_schedule(vector<vector<int>> &arr){
    sort_array_with_deadline(arr);
    int n = arr.size();
    int max_deadline = arr[n-1][1];
    vector<int> slot(max_deadline+1,-1);
    int profit = 0;
    for(int i=n-1;i>=0;i--){
        int slot_available;
        if(i==0){
            slot_available = arr[i][1];
        }
        else{
            slot_available = arr[i][1]-arr[i-1][1];
        }
    }

}


int main(){
    int n = 5;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    //sort_array_with_deadline(arr);    
}