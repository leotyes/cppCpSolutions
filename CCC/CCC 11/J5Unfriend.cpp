#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> vc;

int dfs(int cp) {
    int ans = 1;
    if (dp[cp] != -1) return dp[cp];
    if (vc[cp].empty()) return 1;
    for (int x : vc[cp]) {
        ans *= (dfs(x) + 1);
    }
    dp[cp] = ans;
    return dp[cp];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    dp.resize(n + 1, -1);
    vc.resize(n + 1, vector<int>());

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        vc[x].push_back(i);
    }

    cout << dfs(n);
}