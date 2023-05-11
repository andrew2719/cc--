#include<bits/stdc++.h>
using namespace std;


int min_cost_using_recursion(vector<int> rods, vector<int> costs,vector<int> cut_pieces, int i,int remaining){

    if(i==cut_pieces.size()){
        return 0;
    }
    int min_cost = INT_MAX;
    if(rods[0]>=cut_pieces[i]){
        int cost_with_rod_1 = min(min_cost,costs[0]+min_cost_using_recursion(rods,costs,cut_pieces,i+1,rods[0]-cut_pieces[i]+remaining));
        min_cost = min(min_cost,cost_with_rod_1);
    }

    if(rods[1]>=cut_pieces[i]){
        int cost_with_rod_2 = min(min_cost,costs[1]+min_cost_using_recursion(rods,costs,cut_pieces,i+1,rods[1]-cut_pieces[i]+remaining));
        min_cost = min(min_cost,cost_with_rod_2);
    }

    if(remaining>=cut_pieces[i]){
        int cost_with_remaining = min_cost_using_recursion(rods, costs, cut_pieces, i+1, remaining-cut_pieces[i]);
        min_cost = min(min_cost, cost_with_remaining);
    }
    return min_cost;
}

int using_dp(vector<int> rods, vector<int> costs,vector<int> cut_pieces, int i,int remaining,vector<vector<int>> &dp){
    if(i==cut_pieces.size()){
        return 0;
    }
    if(dp[i][remaining]!=-1){
        return dp[i][remaining];
    }
    int min_cost = INT_MAX;
    if(rods[0]>=cut_pieces[i]){
        int cost_with_rod_1 = min(min_cost,costs[0]+using_dp(rods,costs,cut_pieces,i+1,rods[0]-cut_pieces[i]+remaining,dp));
        min_cost = min(min_cost,cost_with_rod_1);
    }

    if(rods[1]>=cut_pieces[i]){
        int cost_with_rod_2 = min(min_cost,costs[1]+using_dp(rods,costs,cut_pieces,i+1,rods[1]-cut_pieces[i]+remaining,dp));
        min_cost = min(min_cost,cost_with_rod_2);
    }

    if(remaining>=cut_pieces[i]){
        int cost_with_remaining = using_dp(rods, costs, cut_pieces, i+1, remaining-cut_pieces[i],dp);
        min_cost = min(min_cost, cost_with_remaining);
    }
    dp[i][remaining] = min_cost;
    return min_cost;
}


int main(){
    vector<int> rods = {5,10};
    vector<int> costs = {2,3};    
    vector<int> cut_pieces = {1,2,3,4,5,6,7,8,9,10};

    // max piece that can remain
    int dp_n;
    for(int x:cut_pieces){
        dp_n = max(rods[0]-1,rods[1]-x);
    }
    vector<vector<int>> dp(cut_pieces.size(),vector<int>(dp_n+1,-1));

    

    cout<<min_cost_using_recursion(rods,costs,cut_pieces,0,0)<<endl;
    cout<<using_dp(rods,costs,cut_pieces,0,0,dp)<<endl;

    return 0;
}