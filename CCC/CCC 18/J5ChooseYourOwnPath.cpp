#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<vector<int>> vn(n + 1);
    vector<bool> vp(n + 1, false);

    for (int i = 1; i <= n; i++) {
        int mi;

        cin >> mi;

        for (int j = 0; j < mi; j++) {
            int x;
            cin >> x;
            vn[i].push_back(x);
        }
    }

    queue<pair<int, int>> q;

    q.emplace(1, 1);
    vp[0] = true;
    vp[1] = true;
    int amin = INT_MAX;

    while (!q.empty()) {
        for (int x : vn[q.front().first]) {
            if (!vp[x]) {
                vp[x] = true;
                if (vn[x].size() == 0 && amin == INT_MAX) {
                    amin = q.front().second + 1;
                }
                q.emplace(x, q.front().second + 1);
            }
        }
        q.pop();
    }

    if (find(vp.begin(), vp.end(), false) != vp.end()) {
        cout << "N\n";
    } else {
        cout << "Y\n";
    }
    cout << amin;
}