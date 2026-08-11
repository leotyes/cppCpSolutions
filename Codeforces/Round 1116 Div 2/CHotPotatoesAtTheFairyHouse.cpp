#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, rans = 0, bans = 0;
        string s;
        cin >> n >> k >> s;
        if (count(s.begin(), s.end(), '0') == 2 * n) {
            cout << "0 0\n";
            continue;
        } else if (count(s.begin(), s.end(), '1') == 2 * n) {
            cout << n << ' ' << n << '\n';
            continue;
        }
        int streak = 0, firsts = -1;
        vector<int> rs, bs;
        for (int i = 1; i <= 2 * n; i++) {
            int ind = i - 1;
            if (s[ind] == '1' && s[(ind + 1) % (2 * n)] != '0') {
                streak++;
            } else if (s[ind] == '1' && s[(ind + 1) % (2 * n)] == '0') {
                if (firsts == -1) {
                    firsts = i % 2 == 1 ? 1 : 0;
                }
                if (i % 2 == 1) rs.push_back(streak); else bs.push_back(streak);
                streak = 0;
            }
        }
        if (firsts == 1) {
            rs[0] += streak;
        } else {
            bs[0] += streak;
        }
        streak = 0;
        rans = rs.size();
        bans = bs.size();
        for (int x : rs) {
            if (x % 2 == 1) {
                rans += x / 2 + 1;
                bans += x / 2;
            } else {
                rans += x / 2;
                bans += x / 2;
            }
        }
        for (int x : bs) {
            if (x % 2 == 1) {
                bans += x / 2 + 1;
                rans += x / 2;
            } else {
                bans += x / 2;
                rans += x / 2;
            }
        }
        cout << rans << ' ' << bans << '\n';
    }
}