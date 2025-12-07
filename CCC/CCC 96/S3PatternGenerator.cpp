#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void pattern(string cur, int n, int k) {
    if (k < 0) return;
    if (k > n - cur.size()) return;
    if (cur.length() == n) {
        if (k == 0) {
            ans.push_back(cur);
        }
    } else {
        pattern(cur + "1", n, k - 1);
        pattern(cur + "0", n, k);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;

        cin >> n >> k;

        cout << "The bit patterns are\n";

        pattern("", n, k);

        sort(ans.begin(), ans.end(), greater<string>());

        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j] << "\n";
        }

        ans = {};
        if (i != t - 1) {
            cout << "\n";
        }
    }
}