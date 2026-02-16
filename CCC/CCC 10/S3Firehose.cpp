#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, k;

    cin >> h;

    vector<int> vp;

    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        vp.push_back(x);
        vp.push_back(x + 1000000);
    }

    sort(vp.begin(), vp.end());

    cin >> k;

    if (k >= h) {
        cout << 0;
        return 0;
    }

    int lo = 1, hi = 1000000, ans;
    while (lo <= hi) {
        bool w = false;
        int mid = (lo + hi) / 2;
        for (int i = 0; i < h; i++) {
            int nh = 1, end = vp[i] + 2 * mid;
            for (int j = i; j < i + h; j++) {
                if (end < vp[j]) {
                    nh++;
                    end = vp[j] + 2 * mid;
                }
            }
            if (nh <= k) {
                w = true;
                break;
            }
        }
        if (!w) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
}