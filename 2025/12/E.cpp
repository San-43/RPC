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
#define edl '\n'

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
    string s, tmp;
    cin >> s >> tmp;

    const string v1 = R"(\../)";
    const string v2 = R"(.\/.)";
    const string w1 = R"(\../\../)";
    const string w2 = R"(.\/..\/.)";

    string ans = "";
    for (int i = 0; i < n;) {
        if (s[i] == '.' && tmp[i] == '.') {
            ++i;
            continue;
        }
        if (i + 8 <= n && s.compare(i, 8, w1) == 0 && tmp.compare(i, 8, w2) == 0) {
            ans += 'w';
            i += 8;
            continue;
        }
        if (i + 4 <= n && s.compare(i, 4, v1) == 0 && tmp.compare(i, 4, v2) == 0) {
            ans += 'v';
            i += 4;
            continue;
        }
        i++;
    }

    cout << ans << edl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();
    return 0;
}
