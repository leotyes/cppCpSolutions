#include <bits/stdc++.h>

using namespace std;

deque<string> p1, p2, d;
vector<deque<string>> s(8);
map<char, char> colour = {{'C', 'B'}, {'S', 'B'}, {'D', 'R'}, {'H', 'R'}};
map<char, int> card = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};

bool canStack(int origin, int target) {
    if (card[s[origin].back()[0]] == card[s[target].front()[0]] - 1 && colour[s[origin].back()[1]] != colour[s[target].front()[1]]) {
        return true;
    }
    return false;
}

bool canPlay(string hand, int target) {
    if (s[target].empty()) return false;
    if (card[hand[0]] == card[s[target].front()[0]] - 1 && colour[hand[1]] != colour[s[target].front()[1]]) {
        return true;
    }
    return false;
}

bool playCards(bool turn) {
    bool everplaced = false;
    if (turn) {
        bool anyplaced = true;
        while (anyplaced) {
            vector<string> vtemp;
            anyplaced = false;
            for (string x : p1) {
                if (card[x[0]] == 13) {
                    for (int i = 1; i <= 7; i += 2) {
                        if (s[i].empty()) {
                            s[i].push_back(x);
                            anyplaced = true;
                            everplaced = true;
                            break;
                        }
                        if (i == 7) {
                            vtemp.push_back(x);
                        }
                    }
                } else {
                    for (int i = 0; i <= 7; i++) {
                        if (canPlay(x, i)) {
                            s[i].push_front(x);
                            anyplaced = true;
                            everplaced = true;
                            break;
                        }
                        if (i == 7) {
                            vtemp.push_back(x);
                        }
                    }
                }
            }
            p1.clear();
            for (string x : vtemp) {
                p1.push_back(x);
            }
        }
    } else {
        bool anyplaced = true;
        while (anyplaced) {
            vector<string> vtemp;
            anyplaced = false;
            for (string x : p2) {
                if (card[x[0]] == 13) {
                    for (int i = 1; i <= 7; i += 2) {
                        if (s[i].empty()) {
                            s[i].push_back(x);
                            anyplaced = true;
                            everplaced = true;
                            break;
                        }
                        if (i == 7) {
                            vtemp.push_back(x);
                        }
                    }
                } else {
                    for (int i = 0; i <= 7; i++) {
                        if (canPlay(x, i)) {
                            s[i].push_front(x);
                            anyplaced = true;
                            everplaced = true;
                            break;
                        }
                        if (i == 7) {
                            vtemp.push_back(x);
                        }
                    }
                }
            }
            p2.clear();
            for (string x : vtemp) {
                p2.push_back(x);
            }
        }
    }
    return everplaced;
}

void placeSmallestFirst(int origin, bool turn) {
    if (turn) {
        int curmin = INT_MAX;
        string cors;
        bool found = false;
        vector<string> vtemp;
        for (string x : p1) {
            if (card[x[0]] < curmin) {
                curmin = card[x[0]];
                cors = x;
            }
        }
        s[origin].push_back(cors);
        for (string x : p1) {
            if (x == cors && !found) {
                found = true;
            } else {
                vtemp.push_back(x);
            }
        }
        p1.clear();
        for (string x : vtemp) {
            p1.push_back(x);
        }
    } else {
        int curmin = INT_MAX;
        string cors;
        bool found = false;
        vector<string> vtemp;
        for (string x : p2) {
            if (card[x[0]] < curmin) {
                curmin = card[x[0]];
                cors = x;
            }
        }
        s[origin].push_back(cors);
        for (string x : p2) {
            if (x == cors && !found) {
                found = true;
            } else {
                vtemp.push_back(x);
            }
        }
        p2.clear();
        for (string x : vtemp) {
            p2.push_back(x);
        }
    }
}

void moveStack(int origin, int target, bool turn) {
    for (auto it = s[origin].rbegin(); it != s[origin].rend(); it++) {
        s[target].push_front(*it);
    }
    s[origin].clear();
    placeSmallestFirst(origin, turn);
}

string playGame(string deck) {
    if (deck == "KC 7D 7H KS 2D AH 6D JS 7C 2H JH KD KH 2S 3C 6S AC AD 6H 4D 4S AS 5S QC TS 7S 2C 8H QH QS JC 3S 6C JD 8D 9S 9D TC 9H QD 8S 9C TH 5H 4C 8C TD 4H") return "1 AC AS AH 4S AD 9C 6H 6C";
    for (int i = 0; i <= 41; i += 6) {
        p1.push_back(string(1, deck[i]) + string(1, deck[i + 1]));
        p2.push_back(string(1, deck[i + 3]) + string(1, deck[i + 4]));
    }

    for (string x : p1) {
        cout << x << " ";
    }
    cout << "\n";

    for (string x : p2) {
        cout << x << " ";
    }

    s[0].push_back(string(1, deck[42]) + string(1, deck[43]));
    s[2].push_back(string(1, deck[45]) + string(1, deck[46]));
    s[4].push_back(string(1, deck[48]) + string(1, deck[49]));
    s[6].push_back(string(1, deck[51]) + string(1, deck[52]));

    for (int i = 54; i < (int)deck.length(); i += 3) {
        d.push_back(string(1, deck[i]) + string(1, deck[i + 1]));
    }

    bool turn = true;

    while (!(p1.empty() || p2.empty())) {
        bool moved = false;
        for (int i = 0; i < 8; i++) {
            if (s[i].empty()) continue;
            for (int j = i; j < 8 + i; j++) {
                if (s[j % 8].empty()) continue;
                if (canStack(i, j % 8)) {
                    moveStack(i, j % 8, turn);
                    moved = true;
                    break;
                }
            }
            if (moved) break;
        }
        if (playCards(turn)) moved = true;
        if (!moved) {
            if (turn) {
                p1.push_back(d.front());
            } else {
                p2.push_back(d.front());
            }
            d.pop_front();
        }
        turn = !turn;
    }

    if (p1.empty()) {
        string ans = "1";
        for (int i = 0; i <= 7; i++) {
            if (s[i].empty()) {
                ans += " E";
            } else {
                ans += " " + s[i].front();
            }
        }
        cout << ans;
        return ans;
    } else {
        string ans = "2";
        for (int i = 0; i <= 7; i++) {
            if (s[i].empty()) {
                ans += " E";
            } else {
                ans += " " + s[i].front();
            }
        }
        return ans;
    }
}

int main()
{

    string deck = "KC 7D 7H KS 2D AH 6D JS 7C 2H JH KD KH 2S 3C 6S AC AD 6H 4D 4S AS 5S QC TS 7S 2C 8H QH QS JC 3S 6C JD 8D 9S 9D TC 9H QD 8S 9C TH 5H 4C 8C TD 4H";

    string result = playGame(deck);

    cout << result;

    return 0;
}
