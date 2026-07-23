#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int count = 0, err = 0;
    for (char c : s) {
        if (c == '(') {
            count++;
        } else {
            if (count != 0) {
                count--;
            } else {
                err++;
                count++;
            }
        }
        if (err > 1) {
            cout << "NO";
            return 0;
        }
    }
    if (count == 0 || (count == 2 && err == 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}