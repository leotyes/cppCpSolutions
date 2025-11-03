#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int d;
    cin >> d;
    vector<int> ats{34, 71, 83, 95, 107, 119, 130, 142, 154, 166, 178, 201, 213, 225, 237, 260, 272, 284, 296, 331, 343, 355, 390, 402, 414, 461, 473, 520, 532, 591, 671};

    long long ans = 0;

    ans += (d / 720) * 31;
    ans += upper_bound(ats.begin(), ats.end(), d % 720) - ats.begin();

    cout << ans;
}