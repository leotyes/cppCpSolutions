#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

void add(vector<int> cur) {
    int sum = accumulate(cur.begin(), cur.end(), 0);
    if (sum == n) {
        cout << n << '=';
        for (int i = 0; i < cur.size() - 1; i++) {
            cout << cur[i] << '+';
        }
        cout << cur[cur.size() - 1] << "\n";
        ans++;
    } else {
        for (int i = cur[cur.size() - 1]; i <= n - sum; i++) {
            vector<int> cur2 = cur;
            cur2.push_back(i);
            add(cur2);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n / 2; i++) {
        add({i});
    }

    cout << "total=" << ans;
}