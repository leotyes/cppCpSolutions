#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout << "1000000000" << endl;
    long long mmax = 2000000000, mmin = 1;

    while (true) {
        string fs;
        cin >> fs;

        long long mid = (mmax + mmin) / 2;

        if (fs == "OK") break;
        if (fs == "FLOATS") {
            mmax = mid - 1;
        } else {
            mmin = mid + 1;
        }
        cout << (mmax + mmin) / 2 << endl;
    }
}