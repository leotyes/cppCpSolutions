// group B by consecutive numbers, then it must be a subsequence of A, use two pointers to check if B is a subsequence of A
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0, cc = 0;

    cin >> n;

    vector<int> a(n), b(n), breaks;
    queue<int> brm, brmc;
    queue<tuple<char, int, int>> lm;
    stack<tuple<char, int, int>> rm;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (brm.empty()) {
            brm.push(b[i]);
        } else if (brm.back() != b[i]) {
            breaks.push_back(i - 1);
            brm.push(b[i]);
        }
    }

    brmc = brm;

    for (int i = 0; i < n; i++) {
        if (brm.front() == a[i]) {
            brm.pop();
        }
    }

    if (brm.empty()) {
        cout << "YES" << "\n";
    } else {
        cout << "NO";
        return 0;
    }

    while (!brmc.empty()) {
        int cura = find(a.begin(), a.end(), brmc.front()) - a.begin();
        int curb = find(b.begin(), b.end(), brmc.front()) - b.begin();
        if (cura > curb) {
            lm.emplace('L', curb, cura);
            ans++;
        }
        if (cc < breaks.size()) {
            if (cura < breaks[cc]) {
                rm.emplace('R', cura, breaks[cc]);
                ans++;
            }
        } else {
            if (cura < n - 1) {
                rm.emplace('R', cura, n - 1);
                ans++;
            }
        }
        cc++;
        brmc.pop();
    }

    cout << ans << "\n";

    while (!lm.empty()) {
        cout << get<0>(lm.front()) << " " << get<1>(lm.front()) << " " << get<2>(lm.front()) << "\n";
        lm.pop();
    }

    while (!rm.empty()) {
        cout << get<0>(rm.top()) << " " << get<1>(rm.top()) << " " << get<2>(rm.top()) << "\n";
        rm.pop();
    }
}