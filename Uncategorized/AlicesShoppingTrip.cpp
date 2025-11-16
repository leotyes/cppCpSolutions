#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long t;
    int n, ans = 0, prev = 0;
    priority_queue<int> pqp, pqn;

    cin >> t >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 0) {
            pqp.push(-x);
        } else {
            pqn.push(x);
        }
    }

    while ((!pqp.empty() && !pqn.empty()) || t > 0) {
        if (-pqp.top() < -pqn.top() || pqn.empty()) {
            t -= -pqp.top() - prev;
            prev = -pqp.top();
            pqp.pop();
            if (t < 0) break;
            ans++;
        } else {
            t -= -pqn.top() + prev;
            prev = pqn.top();
            pqn.pop();
            if (t < 0) break;
            ans++;
        }
    }

    cout << ans;
}