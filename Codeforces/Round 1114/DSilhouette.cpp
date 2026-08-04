#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, cursum = 0;
        bool f = false;
        cin >> n;
        if (n == 1) {
            int x;
            cin >> x;
            cout << "1\n";
            continue;
        }
        vector<int> vs(n);
        map<int, int> mfreq;
        unordered_map<int, vector<int>> mpos;
        unordered_map<int, int> mans;
        for (int i = 0; i < n; i++) {
            cin >> vs[i];
            mfreq[vs[i]]++;
            mpos[vs[i]].push_back(i);
        }
        if (mfreq.find(0) == mfreq.end()) {
            cout << "-1\n";
            continue;
        }
        int mmin = -1;
        for (auto it = mfreq.begin(); it != mfreq.end(); ++it) {
            auto [v, c] = *it;

            if (next(it) != mfreq.end()) {
                auto [nv, nc] = *next(it);
                int rt = nv - cursum, pans = rt / c;
                if (pans < mmin) {
                    f = true;
                    break;
                }
                if (pans * c == rt) {
                    mans[v] = pans;
                    mmin = pans;
                    cursum += pans * c;
                } else {
                    f = true;
                    break;
                }
            } else {
                mans[v] = mans[prev(it)->first] + 1;
            }
        }
        vector<int> vans(n);
        if (f) {
            cout << "-1\n";
        } else {
            for (auto [v, vpos] : mpos) {
                for (int x : vpos) {
                    vans[x] = mans[v];
                }
            }
            for (int x : vans) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}