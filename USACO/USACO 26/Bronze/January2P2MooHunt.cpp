#include <bits/stdc++.h>
using namespace std;

vector<int> vb;
int n;

void generate(int pos, int mask) {
    if (pos == n) {
        vb.push_back(mask);
        return;
    }
    generate(pos + 1, mask);
    generate(pos + 1, mask | (1 << pos));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, ans = -1, nans = 0;

    cin >> n >> k;

    vector<tuple<int, int, int>> vt;
    map<tuple<int, int, int>, int> mt;

    while (k--) {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        vt.emplace_back(xi, yi, zi);
        mt[make_tuple(xi, yi, zi)]++;
    }

    generate(0, 0);

    for (int mask : vb) {
        int curs = 0;
        for (auto [t, f] : mt) {
            auto [x, y, z] = t;
            if ((mask & 1 << (x - 1)) != 0 && (mask & 1 << (y - 1)) == 0 && (mask & 1 << (z - 1)) == 0) curs += f;
        }
        if (curs > ans) {
            ans = curs;
            nans = 1;
        } else if (curs == ans) {
            nans++;
        }
    }

    cout << ans << " " << nans;
}