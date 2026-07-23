#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans;
    cin >> n;
    ans = (n - 1) * 2;
    vector<int> vn(n);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    for (int i = 0; i < n; i++) {
        if (st.empty() || vn[i] < st.top().first) {
            st.emplace(vn[i], i);
        } else {
            while (!st.empty() && vn[i] > st.top().first) {
                if (i - st.top().second != 1) {
                    ans += i - st.top().second + 1;
                }
                st.pop();
            }
            if (!st.empty() && i - st.top().second != 1) {
                ans += i - st.top().second + 1;
            }
            st.emplace(vn[i], i);
        }
    }
    cout << ans;
}