#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;

    vector<int> v(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(make_pair(v[i], i));
        } else {
            while (!st.empty() && v[i] >= st.top().first) {
                int pv = st.top().first, pi = st.top().second, li, ri = i - pi;
                st.pop();
                if (st.empty()) {
                    li = pi + 1;
                } else {
                    li = pi - st.top().second;
                }
                ans += 1LL * pv * li * ri;
            }
            st.push(make_pair(v[i], i));
        }
    }

    while (!st.empty()) {
        int pv = st.top().first, pi = st.top().second, li, ri = n - pi;
        st.pop();
        if (st.empty()) {
            li = pi + 1;
        } else {
            li = pi - st.top().second;
        }
        ans += 1LL * pv * li * ri;
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(make_pair(v[i], i));
        } else {
            while (!st.empty() && v[i] <= st.top().first) {
                int pv = st.top().first, pi = st.top().second, li, ri = i - pi;
                st.pop();
                if (st.empty()) {
                    li = pi + 1;
                } else {
                    li = pi - st.top().second;
                }
                ans -= 1LL * pv * li * ri;
            }
            st.push(make_pair(v[i], i));
        }
    }

    while (!st.empty()) {
        int pv = st.top().first, pi = st.top().second, li, ri = n - pi;
        st.pop();
        if (st.empty()) {
            li = pi + 1;
        } else {
            li = pi - st.top().second;
        }
        ans -= 1LL * pv * li * ri;
    }

    cout << ans;
}