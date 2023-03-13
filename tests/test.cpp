#include <iostream>
using namespace std;

int main() {
    int n = 9; // number of rows in the pattern

    for (int i = 1; i <= n; i++) { // loop through each row
        for (int j = 1; j <= n - i; j++) { // print spaces before the stars and hashes
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) { // print stars and hashes
            if (k % 2 == 0) { // print hash
                cout << "#";
            } else { // print star
                cout << "*";
            }
        }
        cout << endl; // move to next line
    }
    return 0;
}
