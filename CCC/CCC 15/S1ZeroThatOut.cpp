#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k;
    vector<int> st;

    cin >> k;

    for (int i = 0; i < k; i++) {
        int n;

        cin >> n;

        if (n != 0) {
            st.push_back(n);
        } else {
            st.pop_back();
        }
    }

    cout << accumulate(st.begin(), st.end(), 0);
}