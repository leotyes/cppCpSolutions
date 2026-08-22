#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m1 = 0, m2 = 0, prev = 0, ms = INT_MAX;
    string s;
    cin >> n >> s;
    if (count(s.begin(), s.end(), '0') == n) {
        cout << n - 1;
        return 0;
    }
    if (count(s.begin(), s.end(), '1') == 1) {
        int pos = find(s.begin(), s.end(), '1') - s.begin(), cand = -1;
        if (pos != 0 && pos != n - 1) {
            cand = min(pos, n - 1 - pos);
        }
        cand = max(cand, pos / 2);
        cand = max(cand, (n - 1 - pos) / 2);
        cout << cand;
        return 0;
    }
    int first = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first == -1) {
                first = i;
                prev = i;
                continue;
            }
            if (i - prev >= m1) {
                m2 = m1;
                m1 = i - prev;
            } else if (i - prev > m2) {
                m2 = i - prev;
            }
            if (i - prev < ms) {
                ms = i - prev;
            }
            prev = i;
        }
    }
    int l = first, r = n - 1 - prev, ans = max(m2 / 2, m1 / 3);
    ans = max(ans, l / 2);
    ans = max(ans, r / 2);
    ans = max(ans, min(l, r));
    ans = max(ans, min(l, m1 / 2));
    ans = max(ans, min(r, m1 / 2));
    cout << min(ans, ms);
}