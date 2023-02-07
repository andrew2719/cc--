#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &vec, int left, int right) {
    if (left >= right) return;
    int pivot = vec[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && vec[j] >= pivot) j--;
        if (i < j) vec[i++] = vec[j];
        while (i < j && vec[i] < pivot) i++;
        if (i < j) vec[j--] = vec[i];
    }
    vec[i] = pivot;
    quick_sort(vec, left, i - 1);
    quick_sort(vec, i + 1, right);
}

int main() {
    vector<int> vec{3, 5, 8, 2, 1, 6, 7, 4, 9};
    quick_sort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}