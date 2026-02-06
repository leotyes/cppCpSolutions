#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char, int> md = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    string s;

    cin >> s;
    int ans = 0;

    for (int i = 0; i < s.size() - 2; i += 2) {
        if (md[s[i + 3]] > md[s[i + 1]]) {
            ans -= (s[i] - '0') * md[s[i + 1]];
        } else {
            ans += (s[i] - '0') * md[s[i + 1]];
        }
    }
    ans += (s[s.size() - 2] - '0') * md[s[s.size() - 2 + 1]];

    cout << ans;
}