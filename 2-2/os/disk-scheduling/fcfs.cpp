// disk scheduling algorithm: first come first serve

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, head, seek = 0;
    cout << "Enter the number of requests: ";
    cin >> n;
    int req[n];
    cout << "Enter the requests: ";
    for(int i = 0; i < n; i++)
        cin >> req[i];
    cout << "Enter the initial head position: ";
    cin >> head;
    cout << "Seek Sequence is: ";
    for(int i = 0; i < n; i++)
    {
        cout << head << " ";
        seek += abs(head - req[i]);
        head = req[i];
    }
    cout << endl << "Total seek time: " << seek << endl;
    return 0;
}

// sample i/o

// Enter the number of requests: 8

// Enter the requests: 98 183 37 122 14 124 65 67

// Enter the initial head position: 53

// Seek Sequence is: 53 98 183 37 122 14 124 65 67
// Total seek time: 640

