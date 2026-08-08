#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while (k--) {
        int m, n, ans = 0;
        cin >> m >> n;
        vector<int> vr(n);
        for (int i = 0; i < m; i++) {
            stack<pair<int, int>> st;
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (i == 0) {
                    vr[j] = (c == 'R' ? 0 : 1);
                } else {
                    if (c == 'R') {
                        vr[j] = 0;
                    } else {
                        vr[j]++;
                    }
                }

                if (vr[j] == 0) {
                    int curw = 0;
                    while (!st.empty()) {
                        auto [v, w] = st.top();
                        st.pop();
                        curw += w;
                        ans = max(ans, v * curw);
                    }
                } else {
                    int curw = 0;
                    while (!st.empty() && st.top().first >= vr[j]) {
                        auto [v, w] = st.top();
                        st.pop();
                        curw += w;
                        ans = max(ans, v * curw);
                    }
                    st.emplace(vr[j], curw + 1);
                }
            }
            int curw = 0;
            while (!st.empty()) {
                auto [v, w] = st.top();
                st.pop();
                curw += w;
                ans = max(ans, v * curw);
            }
        }
        cout << ans * 3 << '\n';
    }
}