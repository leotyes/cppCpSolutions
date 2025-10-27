#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    vector<int> psa{a, a + b, a + b + c, a + b + c + d};

    cout << "0 ";

    copy(psa.begin(), psa.end(), ostream_iterator<int>(cout, " "));

    cout << "\n" << psa[0] << " 0";

    for (int i = 1; i < 4; i++) {
        cout << " " << psa[i] - psa[0];
    }

    cout << "\n" << a + b << " " << b << " 0 " << c << " " << c + d;

    cout << "\n" << a + b + c << " " << b + c << " " << c << " 0 " << d;

    cout << "\n" << psa[3] << " " << psa[3] - psa[0] << " " << psa[3] - psa[0] - b << " " << d << " 0";
}