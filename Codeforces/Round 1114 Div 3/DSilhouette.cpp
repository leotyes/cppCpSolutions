#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        if (n == 1) {
            cout << (b[0] == 0 ? "1\n" : "-1\n");
            continue;
        }

        vector<pair<int,int>> vp(n);
        for (int i = 0; i < n; i++) vp[i] = {b[i], i};
        sort(vp.begin(), vp.end());

        if (vp[0].first != 0) {
            cout << "-1\n";
            continue;
        }

        vector<int> a(n);
        bool ok = true;
        int cursum = 0, preva = 0;
        int i = 0;

        while (i < n && ok) {
            int j = i;
            int curb = vp[i].first;
            while (j < n && vp[j].first == curb) j++;
            int cnt = j - i;
            int cura;

            if (j < n) {
                int nextb = vp[j].first;
                int rt = nextb - cursum;
                if (rt <= 0 || rt % cnt != 0) {
                    ok = false;
                    break;
                }
                cura = rt / cnt;
                if (cura <= preva) {
                    ok = false;
                    break;
                }
                cursum += cura * cnt;
            } else {
                cura = preva + 1;
            }

            for (int p = i; p < j; p++) a[vp[p].second] = cura;
            preva = cura;
            i = j;
        }

        if (!ok) {
            cout << "-1\n";
        } else {
            for (int k = 0; k < n; k++) cout << a[k] << ' ';
            cout << '\n';
        }
    }
}