#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);
    int result[n];
    bool slot[n];

    for (int i=0; i<n; i++)
        slot[i] = false;

    for (int i=0; i<n; i++)
    {
        for (int j=min(n, arr[i].deadline)-1; j>=0; j--)
        {
            if (slot[j]==false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int total_profit = 0;
    for (int i=0; i<n; i++)
        if (slot[i])
            total_profit += arr[result[i]].profit;

    cout << "Maximum profit: " << total_profit << endl;
    cout << "Jobs assigned: ";
    for (int i=0; i<n; i++)
        if (slot[i])
            cout << result[i] + 1 << " ";
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++) {
        int deadline, profit;
        cin >> deadline >> profit;
        arr[i] = {deadline, profit};
    }

    printJobScheduling(arr, n);

    return 0;
}
