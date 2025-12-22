#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    long long ans = 0;

    cin >> s;

    vector<long long> vp(17);
    long long mult = 1;

    for (int i = 0; i < 17; i++) {
        vp[i] = mult;
        mult *= 26;
    }

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        ans += (c - 'A' + 1) * vp[s.length() - i - 1];
    }

    cout << ans;
}