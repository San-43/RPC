#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb push_back
#define eld '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    string s;
    getline(cin, s);
    string b;
    getline(cin, b);
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (find(b.begin(), b.end(), s[i]) != b.end())
            continue;
        else {
            if (s[i] != ans.back())
                ans.push_back(s[i]);
        }
    }
    bool ok = false;
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] == ' ' && i == ans.length() - 1) {
            break;
        }

        if (ans[i] != ' ') {
            ok = true;
        } 
        
        if (ok) {
            cout << ans[i];
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}