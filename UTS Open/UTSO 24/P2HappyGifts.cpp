#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k, in; 
    long long m = 0;
    cin >> n >> k;
    vector<int> pns, nns;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in > 0) {
            pns.push_back(in);
        } else if (in < 0) {
            nns.push_back(in);
        }
    }
    sort(pns.begin(), pns.end(), greater<int>());
    sort(nns.begin(), nns.end());
    vector<long long> ppsa(pns.size() + 1, 0), npsa(nns.size() + 1, 0);
    for (int i = 1; i < (int)ppsa.size(); ++i) {
        ppsa[i] = ppsa[i - 1] + pns[i - 1];
    }
    for (int i = 1; i < (int)npsa.size(); ++i) {
        npsa[i] = npsa[i - 1] + nns[i - 1];
    }
    for (int i = 0; i <= min(k, (int)pns.size()); ++i) {
        m = max(m, ppsa[i] - npsa[min((k - i) / 2, (int)nns.size())]);
    }
    cout << m << "\n";
    return 0;
}