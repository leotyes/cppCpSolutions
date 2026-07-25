#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size(), ans = n;
    for (int i = 1; i < n - 1; i++) {
        int m = 0;
        for (int j = 1; j <= n / 2; j++) {
            if (i - j < 0 || i + j >= n) break;
            if (s[i - j] == s[i + j]) {
                ans++;
            } else {
                m++;
                if (m > 1) {
                    break;
                } else {
                    ans++;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int m = 0;
        for (int j = 0; j <= n / 2; j++) {
            if (i - j < 0 || i + j + 1 >= n) break;
            if (s[i - j] == s[i + j + 1]) {
                ans++;
            } else {
                m++;
                if (m > 1) {
                    break;
                } else {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}