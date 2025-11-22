#include <bits/stdc++.h>
using namespace std;

int main1() {
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

// Using custom comparator
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long t, ct = 0;
    int n, prev, ans = 0;

    cin >> t >> n;

    vector<int> xi(n);

    for (int i = 0; i < n; i++) {
        cin >> xi[i];
    }
// Putting & inside the lambda square brackets captures the context
    sort(xi.begin(), xi.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    if (abs(xi[0]) <= t) {
        ans++;
        prev = xi[0];
        ct += abs(xi[0]);
    } else {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < n; i++) {
        ct += abs(xi[i] - prev);
        if (ct > t) {
            cout << ans;
            return 0;
        }
        ans++;
        prev = xi[i];
        // if (prev > 0 && xi[i] > 0) {
        //     ct += xi[i] - prev;
        //     if (ct > t) {
        //         cout << ans;
        //         return 0;
        //     }
        //     ans++;
        // } else if (prev < 0 && xi[i] < 0) {
        //     ct += prev - xi[i];
        //     if (ct > t) {
        //         cout << ans;
        //         return 0;
        //     }
        //     ans++;
        // } else {
        //     ct += abs(prev - xi[i]);
        //
        // }
    }
}