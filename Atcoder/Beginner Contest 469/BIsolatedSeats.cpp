#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            if (s[max(0, i - 1)] == 'x' && s[min(n - 1, i + 1)] == 'x') ans++;
        }
    }

    cout << ans;
}