#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, e = 0, o = 0;
    bool w = false;

    cin >> n;

    vector<ll> vn(n);
    set<ll> se, so;
    vector<ll> ve, vo;

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        if (vn[i] == -1) w = true;
        if (vn[i] % 2 == 0) {
            e++;
            se.insert(i);
            ve.push_back(i + 1);
        } else {
            o++;
            so.insert(i);
            vo.push_back(i + 1);
        }
    }

    if (!w) {
        if (n >= 4) {
            cout << "YES\n";
            if (e >= 2) {
                cout << "1 1\n";
                cout << ve[0] << "\n" << ve[1];
                return 0;
            } else if (o >= 4) {
                cout << "2 2\n";
                cout << vo[0] << " " << vo[1] << "\n" << vo[2] << " " << vo[3];
                return 0;
            } else if (o == 3 && e == 1) {
                cout << "2 1\n";
                cout << vo[0] << " " << vo[1] << "\n";
                cout << ve[0];
            }
        } else if (n == 3) {
            if (gcd(vn[0], vn[1]) != 1) {
                cout << "YES\n";
                cout << "1 1\n";
                cout << "1\n2";
                return 0;
            } else if (gcd(vn[0], vn[2]) != 1) {
                cout << "YES\n";
                cout << "1 1\n";
                cout << "1\n3";
                return 0;
            } else if (gcd(vn[1], vn[2]) != 1) {
                cout << "YES\n";
                cout << "1 1\n";
                cout << "2\n3";
                return 0;
            } else if (gcd(vn[0] + vn[1], vn[2]) != 1) {
                cout << "YES\n";
                cout << "2 1\n";
                cout << "1 2\n3";
                return 0;
            } else if (gcd(vn[1] + vn[2], vn[0]) != 1) {
                cout << "YES\n";
                cout << "2 1\n";
                cout << "2 3\n1";
                return 0;
            } else if (gcd(vn[0] + vn[2], vn[1]) != 1) {
                cout << "YES\n";
                cout << "2 1\n";
                cout << "1 3\n2";
                return 0;
            }
            cout << "NO";
        } else if (n == 2) {
            if (gcd(vn[0], vn[1]) != 1) {
                cout << "YES\n";
                cout << "1 1\n";
                cout << "1\n2";
                return 0;
            }
            cout << "NO";
        }
    } else {
        for (int i = 0; i < 100000; i++) {
            vn[i] = i + 1;
        }
        shuffle(vn.begin(), vn.end(), default_random_engine(1));
        cout << "100";
        for (int i = 0; i < 100; i++) {
            cout << "\n2 2\n";
            cout << vn[i * 4] << " " << vn[i * 4 + 1] << "\n" << vn[i * 4 + 2] << " " << vn[i * 4 + 3];
        }
    }

}