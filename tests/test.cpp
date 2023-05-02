#include<bits/stdc++.h>
using namespace std;

// using recursion
int using_recursion(int n, int r1,int r2, int c1, int c2,vector<int> cut_pieces){
    if(n==0){
        return 0;
    }
    if(cut_pieces[n-1]<=r1 && cut_pieces[n-1]<=r2){
        return min(c1,c2)+using_recursion(n-1,r1,r2,c1,c2,cut_pieces);
    }
    else if(cut_pieces[n-1]<=r1){
        return c1+using_recursion(n-1,r1,r2,c1,c2,cut_pieces);
    }
    else if(cut_pieces[n-1]<=r2){
        return c2+using_recursion(n-1,r1,r2,c1,c2,cut_pieces);
    }
    else{
        return 0+using_recursion(n-1,r1,r2,c1,c2,cut_pieces);
    }
}



int using_dp(int n, int r1,int r2, int c1, int c2,vector<int> cut_pieces){
    int dp[n+1]={0};
    for(int i=1;i<=n;i++){
        if(cut_pieces[i-1]<=r1 && cut_pieces[i-1]<=r2){
            dp[i] = dp[i-1]+min(c1,c2);
        }
        else if(cut_pieces[i-1]<=r1){
            dp[i] = dp[i-1]+c1;
        }
        else if(cut_pieces[i-1]<=r2){
            dp[i] = dp[i-1]+c2;
        }
        else{
            dp[i] = dp[i-1];
        }

    }
    return dp[n];
    // print the dp array
    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
}


int main(){
    int rod_type1_length = 3, rod_type2_length = 5,cost_rod_1 = 2, cost_rod_2 = 3;
    int no_of_cut_pieces;
    //cin>>no_of_cut_pieces;
    no_of_cut_pieces = 5;
    vector<int> cut_pieces = {2,4,1,5,3};
    cout<<"using dp:"<<using_dp(no_of_cut_pieces,rod_type1_length,rod_type2_length,cost_rod_1,cost_rod_2,cut_pieces);
    cout<<"\nusing recursion :"<<using_recursion(no_of_cut_pieces,rod_type1_length,rod_type2_length,cost_rod_1,cost_rod_2,cut_pieces);
    return 0;

   



}