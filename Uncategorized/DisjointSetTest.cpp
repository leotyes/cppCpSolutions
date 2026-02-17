#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return vp[x] == x ? x : vp[x] = parent(vp[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ea = 0;
    
    cin >> n >> m;
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<int> vans;
    vp.resize(n + 1);
    
    for (int i = 0; i <= n; i++) vp[i] = i;
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        pq.emplace(i, a, b);
    }
    
    while (ea < n - 1) {
        if (pq.empty()) {
            cout << "Disconnected Graph";
            return 0;
        }
        auto [cw, ca, cb] = pq.top();
        pq.pop();
        int pca = parent(ca), pcb = parent(cb);
        if (pca != pcb) {
            vans.push_back(cw);
            vp[pca] = pcb;
            ea++;
        }
    }
    
    for (int x : vans) cout << x << "\n";
}