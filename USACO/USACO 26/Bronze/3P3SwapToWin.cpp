#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0;
        string s;
        cin >> n >> m >> s;
        vector<string> vs(n), vans;
        for (int i = 0; i < n; i++) {
            cin >> vs[i];
        }

        for (int i = 0; i < m; i++) {
            if (s[i] == vs[0][i]) continue;
            bool b = false;
            for (int j = i + 1; j < m; j++) {
                if (vs[0][j] == s[i]) {
                    vans.push_back("1 1 " + to_string(i + 1) + " " + to_string(j + 1));
                    string prev = vs[0];
                    vs[0][i] = prev[j];
                    vs[0][j] = prev[i];
                    ans++;
                    b = true;
                    break;
                }
            }
            if (b) continue;
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (vs[j][k] == s[i]) {
                        vans.push_back("1 " + to_string(j + 1) + " " + to_string(i + 1) + " " + to_string(k + 1));
                        string prev0 = vs[0], prev1 = vs[j];
                        vs[j][i] = prev1[k];
                        vs[j][k] = prev1[i];
                        prev1 = vs[j];
                        vans.push_back("2 " + to_string(1) + " " + to_string(j + 1) + " " + to_string(i + 1));
                        vs[0][i] = prev1[i];
                        vs[j][i] = prev0[i];
                        ans += 2;
                        b = true;
                        break;
                    }
                }
                if (b) break;
            }
        }

        cout << ans << '\n';
        for (string sa : vans) {
            cout << sa << '\n';
        }
    }
}