#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;

    vector<tuple<int, int, int, int>> t;

    for (int i = 0; i < n; i++) {
        int xi, yi, zi;

        cin >> xi >> yi >> zi;

        t.emplace_back(xi * yi * zi, xi, yi, zi);
    }

    sort(t.begin(), t.end());

    cin >> m;

    for (int i = 0; i < m; i++) {
        int xi, yi, zi;
        bool d = false;

        cin >> xi >> yi >> zi;


        vector<int> ddim{xi, yi, zi};

        sort(ddim.begin(), ddim.end());

        for (tuple<int, int, int, int> box : t) {
            vector<int> bdim{get<1>(box), get<2>(box), get<3>(box)};

            sort(bdim.begin(), bdim.end());

            if (bdim[0] >= ddim[0] && bdim[1] >= ddim[1] && bdim[2] >= ddim[2]) {
                cout << get<0>(box) << "\n";
                d = true;
                break;
            }

        }
        if (!d) cout << "Item does not fit.\n";
    }
}