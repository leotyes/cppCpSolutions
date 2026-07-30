#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t = 0, ex = 0;
    cin >> n;
    vector<vector<int>> vn(n, vector<int>(n)), v1(n, vector<int>(n, 1)), v2(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vn[i][j];
            if (vn[i][j] < 100) {
                v1[i][j] = 0;
                v2[i][j] = 0;
            } else if (vn[i][j] == 100) {
                v2[i][j] = 0;
            }
        }
    }
    vector<int> vr = v1[0];
    for (int i = 0; i < n; i++) {
        stack<pair<int, int>> st;
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i != 0) {
                if (v1[i][j] == 0) {
                    vr[j] = 0;
                } else {
                    vr[j] += 1;
                }
            }
            if (st.empty() || vr[j] > st.top().first) {
                st.emplace(vr[j], 1);
                s += vr[j];
                t += s;
            } else {
                int wn = 1;
                while (!st.empty() && vr[j] <= st.top().first) {
                    auto [v, w] = st.top();
                    st.pop();
                    s -= v * w;
                    wn += w;
                }
                s += vr[j] * wn;
                st.emplace(vr[j], wn);
                t += s;
            }
        }
    }
    vr = v2[0];
    for (int i = 0; i < n; i++) {
        stack<pair<int, int>> st;
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i != 0) {
                if (v2[i][j] == 0) {
                    vr[j] = 0;
                } else {
                    vr[j] += 1;
                }
            }
            if (st.empty() || vr[j] > st.top().first) {
                st.emplace(vr[j], 1);
                s += vr[j];
                ex += s;
            } else {
                int wn = 1;
                while (!st.empty() && vr[j] <= st.top().first) {
                    auto [v, w] = st.top();
                    st.pop();
                    s -= v * w;
                    wn += w;
                }
                s += vr[j] * wn;
                st.emplace(vr[j], wn);
                ex += s;
            }
        }
    }
    cout << t - ex;
}