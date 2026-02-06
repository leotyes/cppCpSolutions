#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> vind(n + 1);
    vector<vector<int>> vout(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        cin >> vind[i];
        for (int j = 0; j < vind[i]; j++) {
            int pi;
            cin >> pi;
            vout[pi].push_back(i);
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (vind[i] == 0) {
            q.push(i);
        }
    }

    vector<int> vans;

    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        vans.push_back(fr);
        for (int i : vout[fr]) {
            vind[i]--;
            if (vind[i] == 0) {
                q.push(i);
            }
        }
    }

    for (int x : vans) cout << x << " ";
}