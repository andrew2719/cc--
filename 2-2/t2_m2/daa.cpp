
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    n = 5;
    // cout<<"Enter the number of required cut pieces: ";
    // cin>>n;
    int s[n] = {3,5,2,1,4};
    //cout<<"Enter the required cut pieces: ";
    // for(int i=0;i<n;i++)
    // {
    //     cin>>s[i];
    // }
    int r1,r2,c1,c2;
    r1 = 5;
    r2 = 3;
    c1 = 2;
    c2 = 3;
    // cout<<"Enter the length of rod 1: ";
    // cin>>r1;
    // cout<<"Enter the cost of rod 1: ";
    // cin>>c1;
    // cout<<"Enter the length of rod 2: ";
    // cin>>r2;
    // cout<<"Enter the cost of rod 2: ";
    // cin>>c2;
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]<=r1 && s[i-1]<=r2)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+min(c1,c2);
            }
            else if(s[i-1]<=r1)
            {
                dp[i][j]=dp[i-1][j]+c1;
            }
            else if(s[i-1]<=r2)
            {
                cout<<"here"<<endl;
                dp[i][j]=dp[i][j-1]+c2;
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    


    cout<<"The minimum cost is: "<<dp[n][n]<<endl;

    // printing the dp table

    cout<<"The dp table is: "<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}