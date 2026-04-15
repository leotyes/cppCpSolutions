#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> bst;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll k;
    vector<int> vz;
    bst t;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t.insert(x);
    }



    ll lo = 1, hi = 3 * 100000;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
    }
}