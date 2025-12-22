#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long ans = 0;

    cin >> n >> m;

    vector<int> vn(n), vm(m);

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> vm[i];
    }

    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());

    if (n == 1) {
        if (vm[0] < vn[0]) {
            ans += vn[0] - vm[0];
        }
        if (vm[vm.size() - 1] > vn[0]) {
            ans += vm[vm.size() - 1] - vn[0];
        }
        cout << ans;
        return 0;
    }

    if (vm[0] < vn[0]) {
        ans += vn[0] - vm[0];
    }
    if (vm[vm.size() - 1] > vn[vn.size() - 1]) {
        ans += vm[vm.size() - 1] - vn[vn.size() - 1];
    }
    int prevl, minint = INT_MAX;

    for (auto it = upper_bound(vm.begin(), vm.end(), vn[0]); it != upper_bound(vm.begin(), vm.end(), vn[vn.size() - 1]); it++) {
        int curl = *(upper_bound(vn.begin(), vn.end(), *it) - 1), nextl = *upper_bound(vn.begin(), vn.end(), *it), nextp = *(it + 1), curp = *it;

        if (it != upper_bound(vm.begin(), vm.end(), vn[0]) && curl != prevl) {
            ans += minint;
            minint = INT_MAX;
        }
        if (it == vm.begin() || *(it - 1) < curl) {
            minint = min(minint, nextl - curp);
        }
        if (it + 1 != vm.end()) {
            if (nextp > nextl) {
                minint = min(minint, *it - curl);
                prevl = curl;
                continue;
            }
        } else {
            minint = min(minint, curp - curl);
            prevl = curl;
            continue;
        }
        minint = min(minint, curp - curl + nextl - nextp);
        prevl = curl;
    }

    if (minint != INT_MAX) ans += minint;

    cout << ans;
}