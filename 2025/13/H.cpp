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
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < 10 * n; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            if (++m[x] > 2 * n && m[x] > 0) {
                ans.push_back(x);
                m[x] = -INF;
            }
        }
    }
    if (ans.size() == 0) {
        cout << -1 << edl;
        return;
    }
    
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        if(i < ans.size() - 1) {
            cout << ans[i] << " ";
        } else cout << ans[i];
    }

    cout << edl;
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