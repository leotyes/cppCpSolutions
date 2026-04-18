#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    long long ans = 0;
    cin >> n;
    string s = "GOAMPLITUDE";
    for (int i = 0; i < n.length(); i++) {
        ans = (ans * 10 + n[i] - '0') % 11;
    }
    cout << s[(ans + 10) % 11];
}