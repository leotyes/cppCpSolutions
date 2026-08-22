#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    set<int> ans;
    ans.insert(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set<int> ta = ans;
        for (int s : ans) {
            ta.insert(x + s);
        }
        ans = ta;
    }
    cout << ans.size();
}