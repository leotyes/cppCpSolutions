#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int b, f, ans = 0;
    vector<pair<int, int>> batches;
    vector<int> points;
    vector<int> failed;

    cin >> b;

    for (int i = 0; i < b; i++) {
        int fi, ei, pi;

        cin >> fi >> ei >> pi;

        batches.emplace_back(fi, ei);
        points.push_back(pi);
    }

    cin >> f;

    for (int i = 0; i < f; i++) {
        int ti;

        cin >> ti;

        failed.push_back(ti);
    }

    sort(failed.begin(), failed.end());

    for (int i = 0; i < b; i++) {
        if ((lower_bound(failed.begin(), failed.end(), batches[i].first) - failed.begin() == upper_bound(failed.begin(), failed.end(), batches[i].second) - failed.begin())) {
            ans += points[i];
        }
    }

    cout << ans;
}