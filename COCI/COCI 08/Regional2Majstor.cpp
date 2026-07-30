#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, n, a1 = 0, a2 = 0;
    string s;
    cin >> r >> s >> n;
    vector<string> vs(n);
    unordered_map<char, int> m = {{'S', 0}, {'P', 1}, {'R', 2}};
    vector<vector<int>> vt(r, vector<int>(3, 0)), wl = {{1, 2, 0}, {0, 1, 2}, {2, 0, 1}};
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < n; j++) {
            vt[i][m[vs[j][i]]]++;
            a1 += wl[m[s[i]]][m[vs[j][i]]];
        }
        int m = 0;
        for (int j = 0; j < 3; j++) {
            int t = 0;
            for (int k = 0; k < 3; k++) {
                t += wl[j][k] * vt[i][k];
            }
            m = max(m, t);
        }
        a2 += m;
    }
    cout << a1 << '\n' << a2;
}