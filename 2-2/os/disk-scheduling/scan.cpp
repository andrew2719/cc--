// disk scheduling algorithm: scan

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
    cout << "Enter the direction (0 for left, 1 for right): ";
    int dir;
    cin >> dir;
    cout << "Seek Sequence is: ";
    sort(req, req + n);
    int index;
    for(int i = 0; i < n; i++)
    {
        if(req[i] > head)
        {
            index = i;
            break;
        }
    }
    if(dir == 0)
    {
        for(int i = index - 1; i >= 0; i--)
        {
            cout << head << " ";
            seek += abs(head - req[i]);
            head = req[i];
        }
        cout << "0 ";
        seek += head;
        head = 0;
        for(int i = index; i < n; i++)
        {
            cout << head << " ";
            seek += abs(head - req[i]);
            head = req[i];
        }
    }
    else
    {
        for(int i = index; i < n; i++)
        {
            cout << head << " ";
            seek += abs(head - req[i]);
            head = req[i];
        }
        cout << "199 ";
        seek += 199 - head;
        head = 199;
        for(int i = index - 1; i >= 0; i--)
        {
            cout << head << " ";
            seek += abs(head - req[i]);
            head = req[i];
        }
    }
    cout << endl << "Total seek time: " << seek << endl;
    return 0;
}

// sample i/o

// Enter the number of requests: 8

// Enter the requests: 98 183 37 122 14 124 65 67

// Enter the initial head position: 53

// Enter the direction (0 for left, 1 for right): 0

// Seek Sequence is: 53 37 14 0 65 67 98 122 124 183
// Total seek time: 236