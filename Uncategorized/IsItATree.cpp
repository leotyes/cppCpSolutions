#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> sv;
    int edge = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int x;

            cin >> x;

            if (x == 1) {
                sv.insert(i);
                sv.insert(j);
                edge++;
            }
        }
    }

    edge /= 2;

    if (edge == sv.size() - 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}