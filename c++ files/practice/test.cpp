#include<bits/stdc++.h>
using namespace std;

class Class{
    public:
    void inside()
    {
        cout<<"this is inside defination"<<endl;
    }
    void outside();
};

void Class ::outside(){
    cout<<"this is outside defination"<<endl;
}

int main()
{
    Class obj;
    obj.inside();
    obj.outside();
}