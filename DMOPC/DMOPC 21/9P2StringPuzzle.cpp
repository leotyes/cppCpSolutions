#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string a, b, ans = "";
        cin >> a >> b;
        stack<char> st;
        int curp = 0;
        for (int i = 0; i < a.size(); i++) {
            char curl = a[i];
            while (!st.empty() && curl == st.top()) {
                st.pop();
                curl++;
            }
            if (st.empty() && curl == b[curp]) {
                curp++;
                ans += curl;
                continue;
            }
            st.push(curl);
        }
        if (ans == b && st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}