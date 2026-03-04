#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, curx = 0, cury = 0, ans = 0;

    set<pair<int, int>> ss;

    cin >> m;

    ss.emplace(0, 0);

    while (m--) {
        char c;
        int n;
        cin >> c >> n;
        if (c == 'N') {
            int e = cury - n;
            for (; cury > e; ) {
                cury--;
                int prevs = ss.size();
                ss.emplace(curx, cury);
                if (ss.size() == prevs) {
                    ans++;
                }
            }
        } else if (c == 'S') {
            int e = cury + n;
            for (; cury < e; ) {
                cury++;
                int prevs = ss.size();
                ss.emplace(curx, cury);
                if (ss.size() == prevs) {
                    ans++;
                }
            }
        } else if (c == 'E') {
            int e = curx + n;
            for (; curx < e; ) {
                curx++;
                int prevs = ss.size();
                ss.emplace(curx, cury);
                if (ss.size() == prevs) {
                    ans++;
                }
            }
        } else if (c == 'W') {
            int e = curx - n;
            for (; curx > e; ) {
                curx--;
                int prevs = ss.size();
                ss.emplace(curx, cury);
                if (ss.size() == prevs) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}