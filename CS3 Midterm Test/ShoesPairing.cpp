#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<long long> l(n + 1), r(n), li, pre(n), suf(n);
    vector<pair<long long, int>> pi;
    map<int, int> mni;

    for (int i = 0; i <= n; i++) {
        li.push_back(i);
    }

    for (int i = 0; i <= n; i++) {
        cin >> l[i];
        pi.emplace_back(l[i], i);
    }

    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    sort(pi.begin(), pi.end());
    sort(r.begin(), r.end());

    for (int i = 0; i <= n; i++) {
        l[i] = pi[i].first;
        li[i] = pi[i].second;
        mni[pi[i].second] = i;
    }

    pre[0] = max(0LL, l[0] - r[0]);

    for (int i = 1; i < n; i++) {
        pre[i] = max(max(0LL, l[i] - r[i]), pre[i - 1]);
    }

    suf[0] = max(0LL, l[n] - r[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        suf[n - 1 - i] = max(max(0LL, l[i + 1] - r[i]), suf[n - 2 - i]);
    }

    for (int i = 0; i <= n; i++) {
        long long prei, sufi;
        if (mni[i] == 0) {
            prei = 0LL;
        } else {
            prei = pre[mni[i] - 1];
        }
        if (mni[i] == n) {
            sufi = 0;
        } else {
            sufi = suf[n - mni[i] - 1];
        }
        long long ans = max(prei, sufi);
        cout << ans << " ";
    }
}