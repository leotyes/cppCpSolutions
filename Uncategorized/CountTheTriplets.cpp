#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long c = 0;
    map<int, int> freq;
    set<int> unique;

    int n;

    cin >> n;

    vector<int> triples(n);

    for (int i = 0; i < n; i++) {
        cin >> triples[i];
        freq[triples[i]]++;
        unique.insert(triples[i]);
    }

    for (int sum : unique) {
        for (auto it = unique.begin(); it != unique.upper_bound(sum); ++it) {
            if (*it >= sum) continue;
            if (unique.find(sum - *it) != unique.end() && *it != sum - *it) {
                if (*it < sum - *it) {
                    c += freq[*it] * freq[sum - *it] * freq[sum];
                }
            }
        }
    }

    if (c == 0) {
        cout << -1;
    } else {
        cout << c;
    }
}

// int main() {
//     cin.sync_with_stdio(0);
//     cin.tie(0);
//
//     int n;
//
//     cin >> n;
//
//     vector<int> triplets(n);
//
//     for (int i = 0; i < n; i++) {
//         cin >> triplets[i];
//     }
//
//     set<int> st;
//
// }