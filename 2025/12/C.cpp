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
constexpr int kr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
constexpr int kc[8] = {1, -1, 2, -2, 2, -2, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<bool> r(n, 0), c(n, 0);
    vector<bool> d1(2 * n - 1, 0), d2(2 * n - 1, 0);
    vector<vector<bool>> k(n, vector<bool>(n, 0));
    vector<vector<bool>> mismo(n, vector<bool>(n, 0));

    auto ok = [&](int rw, int cl) { return 0 <= rw && rw < n && 0 <= cl && cl < n; };

    for (int i = 0; i < m; ++i) {
        char t;
        int rw, cl;
        cin >> t >> rw >> cl;
        --rw;
        --cl;
        mismo[rw][cl] = 1;

        if (t == 'R' || t == 'Q') {
            r[rw] = 1;
            c[cl] = 1;
        }
        if (t == 'Q') {
            d1[rw - cl + (n - 1)] = 1;
            d2[rw + cl] = 1;
        }
        if (t == 'N') {
            for (int j = 0; j < 8; ++j) {
                int nr = rw + kr[j], nc = cl + kc[j];
                if (ok(nr, nc))
                    k[nr][nc] = 1;
            }
        }
    }

    long long ans = 0;
    for (int rw = 0; rw < n; ++rw) {
        for (int cl = 0; cl < n; ++cl) {
            ans += mismo[rw][cl] ||
                   r[rw] || c[cl] ||
                   d1[rw - cl + (n - 1)] ||
                   d2[rw + cl] ||
                   k[rw][cl];
        }
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
