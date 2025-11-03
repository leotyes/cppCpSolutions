#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    deque<long long> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    while (q.size() > 1) {
        if (q.front() == q.back()) {
            q.pop_back();
            q.pop_front();
        } else {
            if (q.front() < q.back()) {
                int a = q.front(), b;
                q.pop_front();
                b = q.front();
                q.pop_front();
                q.push_front(a + b);
            } else {
                int a = q.back(), b;
                q.pop_back();
                b = q.back();
                q.pop_back();
                q.push_back(a + b);
            }
            ans++;
        }
    }

    cout << ans;
}