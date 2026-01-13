#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sx, sy, ex, ey;

    cin >> sx >> sy >> ex >> ey;

    queue<tuple<int, int, int>> q;
    set<pair<int, int>> visited, dirs{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
    q.push(make_tuple(sx, sy, 0));

    while (get<0>(q.front()) != ex || get<1>(q.front()) != ey) {
        for (auto x : dirs) {
            if (get<0>(q.front()) + x.first > 0 && get<0>(q.front()) + x.first < 9 && get<1>(q.front()) + x.second > 0 && get<1>(q.front()) + x.second < 9) {
                if (visited.find(make_pair(get<0>(q.front()) + x.first, get<1>(q.front()) + x.second)) == visited.end()) {
                    q.push(make_tuple(get<0>(q.front()) + x.first, get<1>(q.front()) + x.second, get<2>(q.front()) + 1));
                    visited.insert(make_pair(get<0>(q.front()) + x.first, get<1>(q.front()) + x.second));
                }
            }
        }
        q.pop();
    }

    cout << get<2>(q.front());
}