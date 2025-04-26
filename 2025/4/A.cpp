#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        list.push_back(s);
    }

    int count = 1;

    for (int i = 0; i< n; i++) {
        if (list[i].length() == m) {
            cout << list[i] << '\n';
            continue;
        }

        int tmp = 0;
        int l = 0;
        int r = 0;
        tmp = m - list[i].length();
 
        
        if (tmp % 2 == 0) {
            l = tmp / 2;
            for (int i = 0; i < l; i++) {
                cout << '.';
            }
            cout << list[i];
            for (int i = 0; i < l; i++) {
                cout << '.';
            }
            cout << endl;
            continue;
        }

        if (count % 2 != 0) {
            l = floor(tmp / 2);
            r = l + 1;
            for (int i = 0; i < l; i++) {
                cout << '.';
            }
            cout << list[i];
            for (int i = 0; i < r; i++) {
                cout << '.';
            }
            cout << endl;
        } else {
            r = floor(tmp / 2);
            l = r + 1;
            for (int i = 0; i < l; i++) {
                cout << '.';
            }
            cout << list[i];
            for (int i = 0; i < r; i++) {
                cout << '.';
            }
            cout << endl;
        }
        count++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}