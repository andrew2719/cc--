#include<bits/stdc++.h>
using namespace std;

int main(){
    map<pair<int,set<int>>,int> mp;
    mp[{1,{2,3,4}}]=5;
    cout<<mp[{1,{2,3,4}}];
}