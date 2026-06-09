#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vn(n), vans;
    queue<int> q0, q1, q2;
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        if (vn[i] % 3 == 0) {
            q0.push(vn[i]);
        } else if (vn[i] % 3 == 1) {
            q1.push(vn[i]);
        } else {
            q2.push(vn[i]);
        }
    }

    if ((q1.size() + q2.size() < q0.size() && q1.size() + q2.size() < q0.size() - 1) || (!q1.empty() && !q2.empty() && q0.empty())) {
        cout << "impossible\n";
        return 0;
    }

    bool alt = true;

    if (q1.size() + q2.size() == q0.size() - 1) {
        alt = false;
    }

    while (!q0.empty()) {
        if (!alt) {
            vans.push_back(q0.front());
            q0.pop();
        } else {
            if (!q1.empty()) {
                vans.push_back(q1.front());
                q1.pop();
            } else {
                vans.push_back(q2.front());
                q2.pop();
            }
        }
        alt = !alt;
    }

    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }

    for (int x : vans) {
        cout << x << " ";
    }

    while (!q2.empty()) {
        if (q2.size() == 1) {
            cout << q2.front();
        } else {
            cout << q2.front() << " ";
        }
        q2.pop();
    }
    cout << "\n";
}