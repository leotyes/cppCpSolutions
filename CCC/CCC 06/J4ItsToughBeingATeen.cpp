#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> vin(8, vector<int>()), vout(8, vector<int>());
    vector<int> vind = {0, 1, 0, 0, 2, 1, 0, 1};
    vin[7].push_back(1);
    vin[4].push_back(1);
    vin[1].push_back(2);
    vin[5].push_back(3);
    vin[4].push_back(3);
    vout[1].push_back(7);
    vout[1].push_back(4);
    vout[2].push_back(1);
    vout[3].push_back(5);
    vout[3].push_back(4);

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        vin[b].push_back(a);
        vind[b]++;
        vout[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= 7; i++) {
        if (vind[i] == 0) pq.push(i);
    }

    vector<int> vans;

    while (!pq.empty()) {
        int fr = pq.top();
        pq.pop();
        vans.push_back(fr);
        for (int i : vout[fr]) {
            vind[i]--;
            if (vind[i] == 0) {
                pq.push(i);
            }
        }
    }

    if (vans.size() != 7) {
        cout << "Cannot complete these tasks. Going to bed.";
    } else {
        for (int i : vans) cout << i << " ";
    }
}