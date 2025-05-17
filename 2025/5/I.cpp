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

    array<int, 5> maxG = {-1, -1, -1, -1, -1};
    int a = 0, b = 0, c = 0;

    while (n--) {
        array<int, 5> g;
        for (int &x : g) cin >> x;

        int cnt = 0;
        for (int i = 0; i < 5; ++i)
            cnt += g[i] > maxG[i];

        if (cnt == 3) ++a;
        else if (cnt == 4) ++b;
        else if (cnt == 5) ++c;

        for (int i = 0; i < 5; ++i)
            maxG[i] = max(maxG[i], g[i]);
    }

    cout << a << " " << b << " " << c << edl;
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