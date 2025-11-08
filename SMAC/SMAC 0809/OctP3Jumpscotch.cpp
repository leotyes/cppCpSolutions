#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, d;

    cin >> n >> d;

    vector<int> ni(n), lo(n);
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        cin >> ni[i];
    }

    lo[0] = ni[0];
    dq.push_back(0);

    for (int i = 1; i < n; i++) {
        lo[i] = ni[i] + lo[dq.front()];
        while (!dq.empty() && dq.front() <= i - d) {
            dq.pop_front();
        }
        while (!dq.empty() && lo[dq.back()] > lo[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << lo[n - 1];
}