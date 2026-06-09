#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s, t;
    cin >> s >> t;
    vector<char> vs(s), vt(t);
    vector<vector<int>> next(s + 1, vector<int>(26, s));
    set<char> sreq, shas;
    for (int i = 0; i < s; i++) {
        cin >> vs[i];
        shas.insert(vs[i]);
    }
    for (int i = 0; i < t; i++) {
        cin >> vt[i];
        if (shas.find(vt[i]) == shas.end()) {
            cout << -1;
            return 0;
        }
        sreq.insert(vt[i]);
    }

    for (auto it = vs.rbegin(); it != vs.rend(); it++) {
        int pos = s - (it - vs.rbegin()) - 1;
        if (pos != s - 1) {
            next[pos] = next[pos + 1];
            next[pos][*it - 'a'] = pos;
        } else {
            next[pos][*it - 'a'] = pos;
        }
    }

    int curp = 0;
    long long ans = 0;

    for (char c : vt) {
        if (next[curp][c - 'a'] != s) {
            curp = next[curp][c - 'a'] + 1;
        } else {
            curp = next[0][c - 'a'] + 1;
            ans += s;
        }
    }

    cout << ans + curp;
}