#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> vreq(m), vans(m, 0);
    unordered_map<int, int> ms, me;
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>> pq;
    vector<tuple<int, int, int>> vr(n + 1);
    set<int> ss;
    for (int i = 0; i < m; i++) {
        cin >> vreq[i];
    }

    for (int i = 0; i < m; i++) {
        if (ss.find(vreq[i]) == ss.end()) {
            ms[vreq[i]] = i;
            ss.insert(vreq[i]);
        }
    }

    ss.clear();

    for (int i = m - 1; i >= 0; i--) {
        if (ss.find(vreq[i]) == ss.end()) {
            me[vreq[i]] = i;
            ss.insert(vreq[i]);
        }
    }

    for (auto [num, pos] : ms) {
        pq.emplace(me[num] - pos, pos, me[num], num);
        vr[num] = make_tuple(me[num] - pos, pos, me[num]);
    }

    stack<int> st;

    for (int i = 0; i < m; i++) {
        auto [xl, xs, xe] = vr[vreq[i]];
        bool b = false;
        if (i == xs) {
            st.push(vreq[i]);
            b = true;
        }
        if (i == xe) {
            b = true;
            if (st.top() == vreq[i]) {
                st.pop();
            } else {
                cout << -1;
                return 0;
            }
        }
        if (b) continue;
        if (vreq[i] == st.top()) continue;
        cout << -1;
        return 0;
    }

    cout << pq.size() << "\n";

    while (!pq.empty()) {
        auto [s, l, r, num] = pq.top();
        pq.pop();
        cout << num << " " << l + 1 << " " << r + 1 << "\n";
    }
}