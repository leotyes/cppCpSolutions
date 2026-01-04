#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, sub = 0;

    cin >> n >> m;

    string s;
    vector<int> vc(n), vr = {0}, vl = {0};

    cin >> s;

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'R' and s[(i + 1) % n] == 'L') {
            ll temp = 0;
            for (int j = (i - 1 + n) % n; s[j] == 'R'; j = (j - 1 + n) % n) {
                temp += vc[j];
            }
            sub += min(temp, m);
            temp = 0;
            for (int j = (i + 2) % n; s[j] == 'L'; j = (j + 1) % n) {
                temp += vc[j];
            }
            sub += min(temp, m);
        }
    }

    cout << accumulate(vc.begin(), vc.end(), 0LL) - sub;
}