#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, curr = 1;
        stack<int> branch, top;

        cin >> n;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            top.push(x);
        }

        while (!top.empty()) {
            if (top.top() == curr) {
                curr++;
                top.pop();
            } else {
                if (!branch.empty()) {
                    if (branch.top() == curr) {
                        curr++;
                        branch.pop();
                        continue;
                    }
                    if (top.top() > branch.top()) {
                        break;
                    } else {
                        branch.push(top.top());
                        top.pop();
                    }
                } else {
                    branch.push(top.top());
                    top.pop();
                }
            }
        }
        if (top.empty()) {
            cout << "Y" << "\n";
        } else {
            cout << "N" << "\n";
        }
    }
}