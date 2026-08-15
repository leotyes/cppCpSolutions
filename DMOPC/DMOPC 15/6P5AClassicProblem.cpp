#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, r = 0, ans = 0;
    deque<pair<int, int>> mind, maxd;
    cin >> n >> k;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }

    for (int l = 0; l < n; l++) {
        while (r < n) {
            while (!maxd.empty() && maxd.back().first <= vn[r]) {
                maxd.pop_back();
            }
            maxd.emplace_back(vn[r], r);
            while (!mind.empty() && mind.back().first >= vn[r]) {
                mind.pop_back();
            }
            mind.emplace_back(vn[r], r);
            if (maxd.front().first - mind.front().first > k) {
                if (maxd.front().second == r) {
                    maxd.pop_front();
                }
                if (mind.front().second == r) {
                    mind.pop_front();
                }
                break;
            }
            r++;
        }
        ans += r - l;
        if (!maxd.empty() && maxd.front().second == l) {
            maxd.pop_front();
        }
        if (!mind.empty() && mind.front().second == l) {
            mind.pop_front();
        }
    }

    cout << ans << '\n';
}