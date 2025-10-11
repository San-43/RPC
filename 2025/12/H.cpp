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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    ll n = (s1.size() + s2.size() + s3.size()) / 2;
    ll i = 0, j = 0, k = 0;
    string ans;
    ans.reserve(n);

    while (ans.size() < n) {
        char a = (i < s1.size() ? s1[i] : 0);
        char b = (j < s2.size() ? s2[j] : 0);
        char c = (k < s3.size() ? s3[k] : 0);

        if (a && b && a == b) {
            ans += a;
            ++i;
            ++j;
        } else if (a && c && a == c) {
            ans += a;
            ++i;
            ++k;
        } else if (b && c && b == c) {
            ans += b;
            ++j;
            ++k;
        } else {
            break;
        }
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
