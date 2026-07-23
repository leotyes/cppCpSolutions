#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    map<pair<int, int>, int> diff;
    unordered_map<int, int> mx, my, mxr, myr;
    vector<vector<int>> vn(1001, vector<int>(1001, 0)), vdiff(1001, vector<int>(1001, 0));

    for (int i = 0; i < n; i++) {
        int xl, yt, xr, yb, ti;
        cin >> xl >> yt >> xr >> yb >> ti;
        diff[make_pair(yt, xl)] += ti;
        diff[make_pair(yt, xr + 1)] -= ti;
        diff[make_pair(yb + 1, xl)] += ti;
        diff[make_pair(yb + 1, xr + 1)] -= ti;
    }

    int prevx = 0, prevy = 0;
    for (auto [p, t] : diff) {
        auto [y, x] = p;
        if (myr.find(y) == myr.end()) {
            prevy++;
            myr[y] = prevy;
            my[prevy] = y;
        }
        if (mxr.find(x) == mxr.end()) {
            prevx++;
            mxr[x] = prevx;
            mx[prevx] = x;
        }
    }

    for (auto [p, t] : diff) {
        auto [y, x] = p;
        vdiff[y][x] = t;
    }


}