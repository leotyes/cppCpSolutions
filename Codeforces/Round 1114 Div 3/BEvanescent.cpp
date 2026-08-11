#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, init = 1;
        string s;
        bool f = false;
        char cur;
        cin >> n >> s;
        cur = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != cur) {
                init++;
                cur = s[i];
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] != s[i - 1] && s[i - 1] == s[i + 1]) {
                f = true;
                cout << init - 2 << '\n';
                break;
            }
        }
        if (f) continue;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
                f = true;
                cout << init - 1 << '\n';
                break;
            }
        }
        if (f) continue;
        cout << init << '\n';
    }
}