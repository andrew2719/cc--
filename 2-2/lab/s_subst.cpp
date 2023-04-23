// sum of subsets problem
// (c) 2002, 2003 duane a. bailey
#include <bits/stdc++.h>
using namespace std;

void printSet(Set<int> s)
// print the elements of s
{
    Set<int>::Iterator i;
    for (i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void sumSubsets(Set<int> s, int target, Set<int> &sofar)
// print all subsets of s whose sum is target
// sofar contains a subset of s that sums to target
{
    if (s.empty())
    {
        if (target == 0)
        {
            printSet(sofar);
        }
    } else {
        int head = s.removeAny();
        sumSubsets(s,target,sofar);
        sofar.add(head);
        sumSubsets(s,target-head,sofar);
        sofar.remove(head);
        s.add(head);
    }
}

int main(int argc, char *argv[])
{
    int i, n, target;
    Set<int> s;
    Set<int> sofar;

    cout << "Enter number of elements in set: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> target;
        s.add(target);
    }
    cout << "Enter target sum: ";
    cin >> target;
    cout << "Subsets with sum " << target << " are:" << endl;
    sumSubsets(s,target,sofar);
    return 0;
}