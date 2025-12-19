#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    bool s = false;

    cin >> n;

    vector<int> va(n), vs;

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (va[i] > va[i + 1]) {
            if (s) {
                vs.push_back(va[i + 1]);
            } else {
                vs.push_back(va[i]);
                vs.push_back(va[i + 1]);
                s = true;
            }
        } else {
            if (s) {
                s = false;
                int med;
                sort(vs.begin(), vs.end());
                med = vs[vs.size() / 2];
                for (int x : vs) {
                    ans += abs(x - med);
                }
                vs.clear();
            }
        }
    }

    if (s) {
        s = false;
        int med;
        sort(vs.begin(), vs.end());
        med = vs[vs.size() / 2];
        for (int x : vs) {
            ans += abs(x - med);
        }
        vs.clear();
    }

    cout << ans;
}