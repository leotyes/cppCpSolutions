#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c, ans = 0;
    cin >> r >> c;
    vector<int> vr(c, 0);

    for (int i = 0; i < r; i++) {
        stack<pair<int, int>> st;
        for (int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            if (ch == 'X') {
                vr[j] = 0;
                int s = 0;
                while (!st.empty()) {
                    auto [v, w] = st.top();
                    st.pop();

                    s += w;

                    ans = max(ans, 2 * (v + s) - 1);
                }
                continue;
            } else {
                vr[j]++;
            }
            int s = 0;
            while (!st.empty() && vr[j] <= st.top().first) {
                auto [v, w] = st.top();
                st.pop();

                s += w;

                ans = max(ans, 2 * (v + s) - 1);
            }
            st.emplace(vr[j], s + 1);
        }
        int s = 0;
        while (!st.empty()) {
            auto [v, w] = st.top();
            st.pop();

            s += w;

            ans = max(ans, 2 * (v + s) - 1);
        }
    }

    cout << ans << '\n';
}