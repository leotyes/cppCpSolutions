#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= log10(*max_element(v.begin(), v.end())) + 1; i++) {
        sort(v.begin(), v.end(), [i](int a, int b) {
           return a % (int)pow(10, i) < b % (int)pow(10, i);
        });
        for (int j = 0; j < n; j++) {
            cout << v[j];
            if (j != n - 1) cout << " ";
        }
        cout << "\n";
    }
}