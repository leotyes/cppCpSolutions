#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    unordered_map<int, vector<int>> adjlist;

    cin >> n >> m;
    vector ans(n + 1, 1);

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        if (a < b) {
            adjlist[b].push_back(a);
        } else {
            adjlist[a].push_back(b);
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<int> available = {1, 2, 3, 4};
        for (int x : adjlist[i]) {
            available.erase(find(available.begin(), available.end(), ans[x]));
        }
        ans[i] = available[0];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
}