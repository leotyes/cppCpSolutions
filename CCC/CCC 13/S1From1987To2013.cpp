#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    while (true) {
        n++;
        string sn = to_string(n);
        set<char> chars(sn.begin(), sn.end());
        if (sn.length() == chars.size()) {
            cout << n;
            break;
        }
    }
}