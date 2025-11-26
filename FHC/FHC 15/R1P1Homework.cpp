#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, maxb = -1;

    cin >> t;

    vector<tuple<int, int, int>> vq(t);

    for (int i = 0; i < t; i++) {
        int ai, bi, ki;

        cin >> ai >> bi >> ki;

        vq[i] = make_tuple(ai, bi, ki);
        maxb = max(maxb, bi);
    }

    vector<int> vp(maxb + 1, 0);

    for (int i = 2; i < maxb + 1; i++) {
        if (vp[i] == 0) {
            int c = i;

            while (c < maxb + 1) {
                vp[c]++;
                c += i;
            }
        }
    }

    vector<vector<long long>> pre(9, vector<long long>(maxb + 1, 0));

    for (int i = 1; i <= 8; i++) {
        for (int j = 2; j < maxb + 1; j++) {
            pre[i][j] = pre[i][j - 1];
            if (vp[j] == i) {
                pre[i][j]++;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        auto [ai, bi, ki] = vq[i];
        cout << "Case #" << i + 1 << ": ";
        if (ki > 8) {
            cout << 0 << "\n";
            continue;
        }

        cout << pre[ki][bi] - pre[ki][ai - 1] << "\n";

    }
}