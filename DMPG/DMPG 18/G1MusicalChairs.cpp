#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> curr(n), st;
    set<int> empty;

    for (int i = 0; i < k; i++) {
        int ki;

        cin >> ki;

        empty.insert(ki);
    }

    for (int i = 0; i <= k; i++) {
        cin >> curr[i];
    }

    for (int i = 0; i < n; i++) {
        auto it = find(curr.begin(), curr.end(), i);
        if (it != curr.end()) {
            st.push_back(it - curr.begin() + 1);
        }
        if (!st.empty() && empty.find(i) != empty.end()) {
            st.pop_back();
        }
    }
    cout << st[0];
}