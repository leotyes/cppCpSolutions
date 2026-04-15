#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> bst;
// You can make a general one like this
// template<class T>
// using bst=tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
// Then do bst<whatever type>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t, as = 0;
    bst bsti;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int s;
        cin >> s;
        auto p = make_pair(s, i);
        bsti.insert(p);
        as += bsti.size() - bsti.order_of_key(p);
    }

    cout << fixed << setprecision(2) << (double)as / t;
}