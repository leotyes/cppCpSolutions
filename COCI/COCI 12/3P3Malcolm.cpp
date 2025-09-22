#include <bits/stdc++.h>
using namespace std;

int COCI123P3Malcolm() {
    int n, k;
    long long c = 0;
    cin >> n >> k;
    vector<int> lens(n), window(k);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        lens[i] = s.length();
    }

    for (int i = 1; i <= k && i < n; i++) {
        freq[lens[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (freq.find(lens[i]) != freq.end()) {
            c += freq[lens[i]];
        }
        if (i + 1 < n) {
            freq[lens[i + 1]]--;
        }
        if (i + k + 1 < n) {
            freq[lens[i + k + 1]]++;
        }
    }

    cout << c;
}