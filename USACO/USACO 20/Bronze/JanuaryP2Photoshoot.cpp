#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> vb(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    for (int i = 1; i <= n; i++) {
        unordered_set<int> stc;
        vector<int> ans;
        int prev = i;
        bool b = false;

        stc.insert(i);

        for (int j = 0; j < n - 1; j++) {
            if (find(stc.begin(), stc.end(), vb[j] - prev) != stc.end() || vb[j] - prev > n || vb[j] - prev <= 0) {
                b = true;
                break;
            }
            stc.insert(vb[j] - prev);
            ans.push_back(vb[j] - prev);
            prev = vb[j] - prev;
        }
        if (b) {
            continue;
        }
        cout << i << " ";
        for (int x : ans) {
            cout << x << " ";
        }
    }
}