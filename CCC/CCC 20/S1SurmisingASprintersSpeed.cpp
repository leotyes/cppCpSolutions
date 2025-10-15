#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> ts, ds;
    set<double> ss;
    vector<pair<int, int>> td;

    for (int i = 0; i < n; i++) {
        int t, x;

        cin >> t >> x;

        ts.push_back(t);
        ds.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        td.push_back(make_pair(ts[i], ds[i]));
    }

    sort(td.begin(), td.end());

    for (int i = 0; i < n; i++) {
        ts[i] = td[i].first;
        ds[i] = td[i].second;
    }

    for (int i = 1; i < n; i++) {
        ss.insert(abs(ds[i] - ds[i - 1]) / (ts[i] - ts[i - 1] * 1.0));
    }

    cout << *ss.rbegin();
}