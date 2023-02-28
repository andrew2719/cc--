// tower of hanoi probelm
#include <iostream>
using namespace std;
void tower(int n, char frompeg, char topeg, char auxpeg)
{
    if(n==0){
        return;
    }
    tower(n-1,frompeg,topeg,auxpeg);
    cout<<"Move disk "<<n<<" from peg "<<frompeg<<" to peg "<<topeg<<endl;
    tower(n-1,auxpeg,topeg,frompeg);
}
int main()
{
int n;
cout<<"Enter the number of disks"<<endl;
cin>>n;
tower(n, 'A', 'C', 'B');
return 0;
}
