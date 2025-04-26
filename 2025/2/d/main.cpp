#include <bits/stdc++.h>

using namespace std;

void solve() {

}

map<char, int> phoneMap;



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    phoneMap['a'] = 2;
    phoneMap['b'] = 2;
    phoneMap['c'] = 2;
    phoneMap['d'] = 3;
    phoneMap['e'] = 3;
    phoneMap['f'] = 3;
    phoneMap['g'] = 4;
    phoneMap['h'] = 4;
    phoneMap['i'] = 4;
    phoneMap['j'] = 5;
    phoneMap['k'] = 5;
    phoneMap['l'] = 5;
    phoneMap['m'] = 6;
    phoneMap['n'] = 6;
    phoneMap['o'] = 6;
    phoneMap['p'] = 7;
    phoneMap['q'] = 7;
    phoneMap['r'] = 7;
    phoneMap['s'] = 7;
    phoneMap['t'] = 8;
    phoneMap['u'] = 8;
    phoneMap['v'] = 8;
    phoneMap['w'] = 9;
    phoneMap['x'] = 9;
    phoneMap['y'] = 9;
    phoneMap['z'] = 9;


    map<string, vector<string>> M;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string t = "";
        for (int j = 0; j < s.length(); j++) {
            t += std::to_string(phoneMap[s[j]]);
        }
        M[t].push_back(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << M[s].size();
        if (!M[s].empty()) {
            cout << " ";
        }
        sort(M[s].begin(), M[s].end());
        for (int j = 0; j < M[s].size(); j++) {
            cout << M[s][j];
            if (j != M[s].size() - 1) {
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}