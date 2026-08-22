#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c;
    vector<int> ans;
    cin >> n >> m >> c;
    vector<int> vn(n);
    deque<pair<int, int>> maxdq, mindq;
    for (int i = 0; i < n; i++) cin >> vn[i];
    for (int i = 0; i < m; i++) {
        while (!maxdq.empty() && maxdq.back().first <= vn[i]) {
            maxdq.pop_back();
        }
        maxdq.emplace_back(vn[i], i);
        while (!mindq.empty() && mindq.back().first >= vn[i]) {
            mindq.pop_back();
        }
        mindq.emplace_back(vn[i], i);
    }
    if (maxdq.front().first - mindq.front().first <= c) ans.push_back(0);
    for (int i = m; i < n; i++) {
        if (maxdq.front().second <= i - m) maxdq.pop_front();
        if (mindq.front().second <= i - m) mindq.pop_front();
        while (!maxdq.empty() && maxdq.back().first <= vn[i]) {
            maxdq.pop_back();
        }
        maxdq.emplace_back(vn[i], i);
        while (!mindq.empty() && mindq.back().first >= vn[i]) {
            mindq.pop_back();
        }
        mindq.emplace_back(vn[i], i);
        if (maxdq.front().first - mindq.front().first <= c) ans.push_back(i - m + 1);
    }
    for (int x : ans) {
        cout << x + 1 << '\n';
    }
    if (ans.size() == 0) cout << "NONE\n";
}