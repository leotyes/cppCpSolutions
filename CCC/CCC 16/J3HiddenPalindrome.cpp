#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    int ans = 0;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        int ri = i + 1, li = i - 1;
        while (li >= 0 && ri < s.length()) {
            if (s[ri] == s[li]) {
                ans = max(ri - li + 1, ans);
                ri++;
                li--;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < s.length(); i++) {
        int ri = i + 1, li = i;
        while (li >= 0 && ri < s.length()) {
            if (s[ri] == s[li]) {
                ans = max(ri - li + 1, ans);
                ri++;
                li--;
            } else {
                break;
            }
        }
    }

    cout << ans;
}