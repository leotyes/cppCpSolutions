#include <bits/stdc++.h>
using namespace std;
#define int long long

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, div;
    string ans = "";
    unordered_map<char, int> mc = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}};
    cin >> mc['A'] >> mc['B'] >> mc['C'] >> mc['D'] >> k;
    int t = mc['A'] + mc['B'] + mc['C'] + mc['D'], ot = t;
    div = fact(t) / (fact(mc['A']) * fact(mc['B']) * fact(mc['C']) * fact(mc['D']));
    for (int i = 0; i < ot; i++) {
        for (char c = 'A'; c <= 'D'; c++) {
            if (mc[c] == 0) continue;
            int ps = div * mc[c] / t;
            if (k <= ps) {
                ans += c;
                mc[c]--;
                div = ps;
                t--;
                break;
            }
            k -= ps;
        }
    }
    cout << ans;
}