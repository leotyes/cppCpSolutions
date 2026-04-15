#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string x;
    cin >> n >> m >> x;
    vector<int> vs(m), vzi;

    for (int i = 0; i < m; i++) {
        cin >> vs[i];
    }

    int smax = *max_element(vs.begin(), vs.end()), sin;

    for (int i = 0; i < n; i++) {
        if (x[i] == '0') vzi.push_back(i);
    }

    for (auto it = vs.rbegin(); it != vs.rend(); it++) {
        if (*it == smax) {
            sin = vzi[m - (it - vs.rbegin()) - 1];
            break;
        }
    }

    for (int i = sin; i < sin + n; i++) {
        if (x[i % n] != '0') {
            cout << x[i % n];
        }
    }
    cout << "\n";
}