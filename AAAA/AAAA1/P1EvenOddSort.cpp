#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, co = 0, ce = 0;

    cin >> n;

    vector<int> vn(n);

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        if (vn[i] % 2 == 0) {
            ce++;
        } else {
            co++;
        }
    }

    if (n % 2 == 1) {
        cout << "Steven";
    } else {
        if (co > ce) {
            cout << "Todd";
        } else {
            cout << "Steven";
        }
    }
}