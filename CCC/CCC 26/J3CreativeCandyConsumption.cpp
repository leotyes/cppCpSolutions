#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    int aans = 0, bans = 0;
    
    cin >> a >> b;
    
    queue<char> qa, qb;
    
    for (char x : a) {
        qa.push(x);
    }
    
    for (char x : b) {
        qb.push(x);
    }
    
    while (!qb.empty() && !qa.empty()) {
        if (qa.front() == qb.front()) {
            qa.pop();
            qb.pop();
            aans++;
            bans++;
        } else if (qa.front() == 'R') {
            if (qb.front() == 'G') {
                qb.pop();
                aans++;
            } else {
                qa.pop();
                bans++;
            }
        } else if (qa.front() == 'G') {
            if (qb.front() == 'B') {
                qb.pop();
                aans++;
            } else {
                qa.pop();
                bans++;
            }
        } else if (qa.front() == 'B') {
            if (qb.front() == 'R') {
                qb.pop();
                aans++;
            } else {
                qa.pop();
                bans++;
            }
        }
    }
    
    aans += qa.size();
    bans += qb.size();
    
    cout << aans << "\n" << bans;
}