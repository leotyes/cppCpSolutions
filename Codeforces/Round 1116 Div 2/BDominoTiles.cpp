#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        bool b = false;
        cin >> n >> s;
        if (count(s.begin(), s.end(), '?') == n) {
            cout << "4\n";
            continue;
        }
        for (int i = 0; i < n - 2; i++) {
            if (s[i] != '?' && s[i] == s[i + 2]) {
                b = true;
                break;
            }
            if (s[i] != '?' && s[i + 2] == '?') {
                s[i + 2] = s[i] == '0' ? '1' : '0';
            }
        }
        if (b) {
            cout << "0\n";
            continue;
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < n - 2; i++) {
            if (s[i] != '?' && s[i] == s[i + 2]) {
                b = true;
                break;
            }
            if (s[i] != '?' && s[i + 2] == '?') {
                s[i + 2] = s[i] == '0' ? '1' : '0';
            } else if (s[i] == '?' && s[i + 2] != '?') {
                s[i] = s[i + 2] == '0' ? '1' : '0';
            }
        }
        if (b) {
            cout << "0\n";
            continue;
        }
        if (find(s.begin(), s.end(), '?') != s.end()) {
            cout << "2\n";
            continue;
        }
        cout << "1\n";
    }
}