#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, dist = 0;
    long long k;

    cin >> n >> k;

    vector<int> vn(n + 1);
    int slow = 1, fast = 1;
    bool s = false;

    for (int i = 1; i <= n; i++) {
        cin >> vn[i];
    }

    while (slow != fast || !s) {
        s = true;
        slow = vn[slow];
        fast = vn[fast];
        fast = vn[fast];
    }

    slow = 1;

    while (slow != fast) {
        slow = vn[slow];
        fast = vn[fast];
    }

    vector<int> vc;
    fast = vn[fast];
    vc.push_back(slow);

    while (slow != fast) {
        vc.push_back(fast);
        fast = vn[fast];
    }

    fast = 1;

    while (slow != fast) {
        dist++;
        fast = vn[fast];
    }

    fast = 1;

    if (k < dist) {
        for (int i = 0; i < k; i++) {
            fast = vn[fast];
        }

        cout << fast;
    } else {
        cout << vc[(k - dist) % vc.size()];
    }
}