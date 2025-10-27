#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> hv(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        cin >> hv[i];
    }

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            cout << "0 ";
            st.push(make_pair(hv[i], i));
        } else {
            while (!st.empty() && st.top().first <= hv[i]) {
                st.pop();
            }
            if (st.empty()) {
                cout << i << " ";
            } else {
                cout << i - st.top().second << " ";
            }
            st.push(make_pair(hv[i], i));
        }
    }
}