#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> vn;

long long check(long long cp) {
    long long ans = 0;
    if (cp < 0 || cp > 1000000000) return LLONG_MAX;
    for (auto [pi, wi, di] : vn) {
        if (!(pi >= cp - di && pi <= cp + di)) {
            ans += wi * (min(llabs(pi - (cp + di)), llabs(pi - (cp - di))));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int pi, wi, di;
        cin >> pi >> wi >> di;
        vn.emplace_back(pi, wi, di);
    }

    long long lo = 0, hi = 1000000000, ans;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2, ic = check(mid), in = check(mid + 1);
        ans = ic;
        if (lo == hi) {
            break;
        }
        if (ic < in) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans;
}