#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    unordered_map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        freq[s]++;
    }
    for (auto [s, v] : freq) {
        ans = max(ans, v);
    }
    cout << ans;
}