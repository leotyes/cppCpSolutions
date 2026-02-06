#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp(251, vector<vector<int>>(251, vector<int>(251, 0)));

int sums(int no, int p, int c) {
    int max = p / no;
    if (p == no) {
        dp[no][p][c] = 1;
    } else if (no == 1) {
        dp[no][p][c] = 1;
    } else {
        int cc = 0;
        for (int i = c; i <= max; i++) {
            if (dp[no - 1][p - i][i] == 0) {
                dp[no - 1][p - i][i] = sums(no - 1, p - i, i);
            }
            cc += dp[no - 1][p - i][i];
        }
        dp[no][p][c] = cc;
    }
    return dp[no][p][c];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;

    cin >> n >> k;
    if (n == k) {
        cout << "1";
    }
    else {
        cout << sums(k, n, 1);
    }
}

