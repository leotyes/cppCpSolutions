#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    set<int> window;

    cin >> n;

    string ans, wans;

    cin >> ans >> wans;

    for (int i = 0; i < n - 1; i++) {
        if (ans[i] == wans[i]) {
            window.insert(i);
        }
    }

    s = window.size();

    for (int i = 0; i < n - 1; i++) {
        window.erase(n - i - 2);
        if (ans[n - i - 1] == wans[n - i - 2]) {
            window.insert(n - i - 1);
            s = max(s, static_cast<int>(window.size()));
        }
    }

    cout << s;
}