#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    string s;
    stack<char> st;

    cin >> n >> q >> s;

    vector<int> pre(n, 1), suf(n, 1);

    st.push(s[0]);

    for (int i = 1; i < n; i++) {
        if (s[i] > st.top()) {
            pre[i] = pre[i - 1] + 1;
            st.push(s[i]);
        } else if (s[i] == st.top()) {
            pre[i] = pre[i - 1];
        } else {
            while (!st.empty() && s[i] < st.top()) {
                st.pop();
            }
            if (st.empty() || st.top() < s[i]) {
                pre[i] = pre[i - 1] + 1;
                st.push(s[i]);
            } else {
                pre[i] = pre[i - 1];
            }
        }
    }

    while (!st.empty()) {
        st.pop();
    }

    st.push(s[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        int si = n - 1 - i;
        if (s[i] > st.top()) {
            suf[si] = suf[si - 1] + 1;
            st.push(s[i]);
        } else if (s[i] == st.top()) {
            suf[si] = suf[si - 1];
        } else {
            while (!st.empty() && s[i] < st.top()) {
                st.pop();
            }
            if (st.empty() || st.top() < s[i]) {
                suf[si] = suf[si - 1] + 1;
                st.push(s[i]);
            } else {
                suf[si] = suf[si - 1];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int preans = 0, sufans = 0;

        if (a - 2 < 0) {
            preans = 0;
        } else {
            preans = pre[a - 2];
        }

        if (n - b - 1 < 0) {
            sufans = 0;
        } else {
            sufans = suf[n - b - 1];
        }

        cout << preans + sufans << "\n";
    }
}