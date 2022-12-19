#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int front=0,rear;
    vector<int> a;
    for(rear=0;rear<n;rear++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    while(rear!=front)
    {
        if(*(a.begin())%2==0)
        cout<<a[front]<<"-even"<<endl;
        else
        cout<<a[front]<<"-odd"<<endl;
        front++;
        a.erase(a.begin());
        
    }
}