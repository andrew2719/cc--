#include<bits/stdc++.h>
using namespace std;


class myclass_2
{
    public:
    void fun_in_myclas_2()
    {
        cout<<"this is a function in myclass 2 using multiple inheritance"<<endl;
    }
};
class myclass
{
    public:
    myclass()//constructor
    {
        cout<<"this is constructor"<<endl;
    }
    void fun_in_myclass()
    {
        cout<<"this is function in myclass class"<<endl;
    }

};

class inheritance : public myclass, public myclass_2
{
    public:
    void fun_in_inheritance()
    {
        fun_in_myclass();
        cout<<"above one is called by inheritance"<<endl;
    }
};
int main()
{
    inheritance obj1;
    obj1.fun_in_myclass();// using inheritance calling a function in myclass
    obj1.fun_in_myclas_2(); // using multiple inheritance
}