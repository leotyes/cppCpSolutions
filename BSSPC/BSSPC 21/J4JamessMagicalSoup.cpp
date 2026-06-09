#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n, ans = 0;
    cin >> x >> n;
    vector<vector<int>> vt(500001, vector<int>());

    for (int i = 0; i < n; i++) {
        int ti, fi, st;
        cin >> ti >> fi;
        if (ti - x > fi) continue;
        st = max(ti - x, 0);
        vt[st].push_back(fi);
    }

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i <= 500000; i++) {
        for (int r : vt[i]) {
            pq.push(r);
        }
        while (!pq.empty() && pq.top() < i) {
            pq.pop();
        }
        if (!pq.empty()) {
            pq.pop();
            ans++;
        }
    }

    cout << ans;
}