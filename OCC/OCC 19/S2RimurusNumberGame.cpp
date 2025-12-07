#include <bits/stdc++.h>
using namespace std;

long long n, ans = 0;

void game(string cur) {
    if (stoll(cur) <= n) {
        ans++;
        game(cur + "2");
        game(cur + "3");
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    game("2");
    game("3");

    cout << ans;
}