#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <utility>

using namespace std;

/*
 * Complete the 'findCreature' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING input1
 *  2. STRING input2
 *  3. STRING input3
 */

string findCreature(string input1, string input2, string input3) {
    int fr, fc, sr, sc, tr, tc;
    set<pair<int, int>> s1, s2, s3;
    vector<int> p16{1, 16};
    fr = fc = sr = sc = tr = tc = 0;
    map<char, int> ma{{'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
    map<int, char> mn{{10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

    for (int i = 0; i < 2; i++) {
        if (ma.count(input1[i])) {
            fr += p16[2 - i - 1] * ma[input1[i]];
        } else {
            fr += p16[2 - i - 1] * (input1[i] - '0');
        }
    }

    for (int i = 2; i < 4; i++) {
        if (ma.count(input1[i])) {
            fc += p16[4 - i - 1] * ma[input1[i]];
        } else {
            fc += p16[4 - i - 1] * (input1[i] - '0');
        }
    }

    for (int i = 0; i < 2; i++) {
        if (ma.count(input2[i])) {
            sr += p16[2 - i - 1] * ma[input2[i]];
        } else {
            sr += p16[2 - i - 1] * (input2[i] - '0');
        }
    }

    for (int i = 2; i < 4; i++) {
        if (ma.count(input2[i])) {
            sc += p16[4 - i - 1] * ma[input2[i]];
        } else {
            sc += p16[4 - i - 1] * (input2[i] - '0');
        }
    }

    for (int i = 0; i < 2; i++) {
        if (ma.count(input3[i])) {
            tr += p16[2 - i - 1] * ma[input3[i]];
        } else {
            tr += p16[2 - i - 1] * (input3[i] - '0');
        }
    }

    for (int i = 2; i < 4; i++) {
        if (ma.count(input3[i])) {
            tc += p16[4 - i - 1] * ma[input3[i]];
        } else {
            tc += p16[4 - i - 1] * (input3[i] - '0');
        }
    }

    int fdr, fdc, sdr, sdc, tdr, tdc;
    int fgr = fr, fgc = fc, sgr = sr, sgc = sc, tgr = tr, tgc = tc;

    fdr = fdc = sdr = sdc = tdr = tdc = 0;

    for (int i = 5; i < 7; i++) {
        if (ma.count(input1[i])) {
            fdr += p16[7 - i - 1] * ma[input1[i]];
        } else {
            fdr += p16[7 - i - 1] * (input1[i] - '0');
        }
    }

    for (int i = 7; i < 9; i++) {
        if (ma.count(input1[i])) {
            fdc += p16[9 - i - 1] * ma[input1[i]];
        } else {
            fdc += p16[9 - i - 1] * (input1[i] - '0');
        }
    }

    s1.insert(make_pair(fgr + fdr, fgc + fdc));
    s1.insert(make_pair(fgr + fdr, fgc - fdc));
    s1.insert(make_pair(fgr - fdr, fgc + fdc));
    s1.insert(make_pair(fgr - fdr, fgc - fdc));
    s1.insert(make_pair(fgr + fdc, fgc + fdr));
    s1.insert(make_pair(fgr + fdc, fgc - fdr));
    s1.insert(make_pair(fgr - fdc, fgc + fdr));
    s1.insert(make_pair(fgr - fdc, fgc - fdr));

    for (int i = 5; i < 7; i++) {
        if (ma.count(input2[i])) {
            sdr += p16[7 - i - 1] * ma[input2[i]];
        } else {
            sdr += p16[7 - i - 1] * (input2[i] - '0');
        }
    }

    for (int i = 7; i < 9; i++) {
        if (ma.count(input2[i])) {
            sdc += p16[9 - i - 1] * ma[input2[i]];
        } else {
            sdc += p16[9 - i - 1] * (input2[i] - '0');
        }
    }

    s2.insert(make_pair(sgr + sdr, sgc + sdc));
    s2.insert(make_pair(sgr + sdr, sgc - sdc));
    s2.insert(make_pair(sgr - sdr, sgc + sdc));
    s2.insert(make_pair(sgr - sdr, sgc - sdc));
    s2.insert(make_pair(sgr + sdc, sgc + sdr));
    s2.insert(make_pair(sgr + sdc, sgc - sdr));
    s2.insert(make_pair(sgr - sdc, sgc + sdr));
    s2.insert(make_pair(sgr - sdc, sgc - sdr));

    for (int i = 5; i < 7; i++) {
        if (ma.count(input3[i])) {
            tdr += p16[7 - i - 1] * ma[input3[i]];
        } else {
            tdr += p16[7 - i - 1] * (input3[i] - '0');
        }
    }

    for (int i = 7; i < 9; i++) {
        if (ma.count(input3[i])) {
            tdc += p16[9 - i - 1] * ma[input3[i]];
        } else {
            tdc += p16[9 - i - 1] * (input3[i] - '0');
        }
    }

    s3.insert(make_pair(tgr + tdr, tgc + tdc));
    s3.insert(make_pair(tgr + tdr, tgc - tdc));
    s3.insert(make_pair(tgr - tdr, tgc + tdc));
    s3.insert(make_pair(tgr - tdr, tgc - tdc));
    s3.insert(make_pair(tgr + tdc, tgc + tdr));
    s3.insert(make_pair(tgr + tdc, tgc - tdr));
    s3.insert(make_pair(tgr - tdc, tgc + tdr));
    s3.insert(make_pair(tgr - tdc, tgc - tdr));

    vector<pair<int, int>> vinter;

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(vinter));
    set_intersection(vinter.begin(), vinter.end(), s3.begin(), s3.end(), back_inserter(vinter));

    set<pair<int, int>> sinter(vinter.begin(), vinter.end());

    for (auto x : sinter) {
        if (!(x.first >= 0 && x.first <= 255 && x.second >= 0 && x.second <= 255)) {
            sinter.erase(x);
        }
    }

    pair<int, int> pans = *sinter.begin();
    string a1 = "", a2 = "";

    if ((pans.first / 16) > 9) {
        a1 += mn[pans.first / 16];
    } else {
        a1 += (pans.first / 16) + '0';
    }

    if ((pans.first % 16) > 9) {
        a1 += mn[pans.first % 16];
    } else {
        a1 += (pans.first % 16) + '0';
    }

    if ((pans.second / 16) > 9) {
        a2 += mn[pans.second / 16];
    } else {
        a2 += (pans.second / 16) + '0';
    }

    if ((pans.second % 16) > 9) {
        a2 += mn[pans.second % 16];
    } else {
        a2 += (pans.second % 16) + '0';
    }

    return "(" + a1 + "," + a2 + ")";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string input1;
    getline(cin, input1);

    string input2;
    getline(cin, input2);

    string input3;
    getline(cin, input3);

    string result = findCreature(input1, input2, input3);

    fout << result << "\n";

    fout.close();

    return 0;
}
