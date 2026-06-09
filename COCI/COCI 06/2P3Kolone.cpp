#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, t;
    string s1, s2;
    cin >> n1 >> n2 >> s1 >> s2 >> t;
    reverse(s1.begin(), s1.end());
    string cur = s1 + s2;
    vector<bool> vd(cur.length(), false);
    for (int i = 0; i < s1.length(); i++) vd[i] = true;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < cur.length() - 1; j++) {
            if (vd[j] && !vd[j + 1]) {
                swap(cur[j], cur[j + 1]);
                swap(vd[j], vd[j + 1]);
                j++;
            }
        }
    }

    cout << cur;
}