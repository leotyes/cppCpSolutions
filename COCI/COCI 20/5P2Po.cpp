#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<int> vn(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    for (int i = 0; i < n; i++) {
        if ((st.empty() || vn[i] > st.top()) && vn[i] != 0) {
            st.push(vn[i]);
        } else if (!st.empty() && vn[i] < st.top()) {
            while (!st.empty() && vn[i] < st.top()) {
                st.pop();
                ans++;
            }
            if ((st.empty() || st.top() != vn[i]) && vn[i] != 0) {
                st.push(vn[i]);
            }
        }
    }
    ans += st.size();
    cout << ans;
}