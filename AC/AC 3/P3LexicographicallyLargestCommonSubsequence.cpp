#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> vs(n);
    string ans = "";
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }
    for (char c = 'z'; c >= 'a'; c--) {
        bool b = false;
        while (!b) {
            for (string s : vs) {
                if (s.find(c) == string::npos) {
                    b = true;
                    break;
                }
            }
            if (b) break;
            ans += c;
            for (string &s : vs) {
                s.erase(0, s.find(c) + 1);
            }
        }
    }
    if (ans.empty()) cout << "-1\n"; else cout << ans << '\n';
}