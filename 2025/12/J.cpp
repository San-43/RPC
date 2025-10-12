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
    int n, m;
    cin >> n >> m;

    vector<int> a(m + 2, 0);

    for (int i = 0; i < n; ++i) {
        int v; 
        cin >> v;
        for (int j = 0; j < v; ++j) {
            int s, e; 
            cin >> s >> e;       
            ++a[s];
            if (e + 1 <= m) --a[e + 1];
        }
    }

    int tmp = 0, ans = 0;
    for (int d = 1; d <= m; ++d) {
        tmp += a[d];         
        if (n - tmp >= 3) ++ans; 
    }

    cout << ans << edl;
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
