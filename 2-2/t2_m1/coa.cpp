#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // covert to binary of -32 to 31
    int bin[6] = {0};
    bitset<6> b(abs(n));
    cout<<b<<endl;

    if(n<0){
        cout<<"Negative"<<endl;
        cout<<"signed magnitude: is - "<<0<<", -bin value is :"<<b<<endl;

        // 2's complement
        for(int i=5; i>=0; i--){
            if(b[i]==0){
                b[i] = 1;
                break;
            }
            else{
                b[i] = 0;
            }
        }
        cout<<"2's complement: is - "<<0<<", -bin value is :"<<b<<endl;
    }
    
}