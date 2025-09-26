#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, istart = 0, iend;
    long long ans = 0, m;

    cin >> n >> m;

    vector<int> nums(n);

    iend = n - 1;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    while (istart < iend) {
        long long sum = nums[istart] + nums[iend];
        if (sum <= m) {
            ans += (iend - istart);
            istart++;
        } else {
            iend--;
        }
    }
    cout << ans % (1000000007);
}