#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t >> n;

    if (t == 1) {
        vector<int> vh(n);

        for (int i = 0; i < n; i++) {
            cin >> vh[i];
        }

        stack<int> s1, s2;
        int isls = 0;

        for (int i = 0; i < n; i++) {
            if (vh[i] >= 1) {
                s1.push(vh[i]);
            } else {
                if (!s1.empty() && s1.top() != 0) {
                    isls++;
                    s1.push(0);
                }
            }
        }

        if (!s1.empty() && s1.top() != 0) {
            isls++;
        }

        cout << isls << " ";

        for (int i = 2; i <= n; i++) {
            int ans = 0;
            if (i % 2 == 0) {
                while (!s1.empty()) {
                    if (s1.top() >= i) {
                        s2.push(s1.top());
                        s1.pop();
                    } else {
                        if (!s2.empty() && s2.top() != 0) {
                            ans++;
                            s2.push(0);
                        }
                        s1.pop();
                    }
                }
                if (!s2.empty() && s2.top() != 0) {
                    ans++;
                }
            } else {
                while (!s2.empty()) {
                    if (s2.top() >= i) {
                        s1.push(s2.top());
                        s2.pop();
                    } else {
                        if (!s1.empty() && s1.top() != 0) {
                            ans++;
                            s1.push(0);
                        }
                        s2.pop();
                    }
                }
                if (!s1.empty() && s1.top() != 0) {
                    ans++;
                }
            }
            cout << ans << " ";
        }
    }
}