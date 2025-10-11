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

template <typename T>
void fill_seq(vector<T> &v, T start = 1) {
    iota(v.begin(), v.end(), start);
}

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int ans = 0;

void dfs(int x, int y, vector<vector<char>>& v, vector<vector<bool>>& visited, map<pair<int, int>, int>& mp ) {
    int n = v.size();
    int m = v[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || v[x][y] == 'W') {
        return;
    }

    visited[x][y] = true;
    ans = max(mp[make_pair(x,y)], ans);
    dfs(x + 1, y, v, visited, mp);
    dfs(x - 1, y, v, visited, mp);
    dfs(x, y + 1, v, visited, mp);
    dfs(x, y - 1, v, visited, mp);

    visited[x][y] = false;
}


void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m, 0));
    vector<pair<int, int>> w;
    vector<pair<int, int>> wt;
    for(int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'W')
                w.emplace_back(i, j);
            else {
                wt.emplace_back(i, j);
            }
        }
    }

    map<pair<int, int>, int> mp;
    for(int i = 0; i < wt.size(); i++) {
        for(int j = 0; j < w.size(); j++) {
            int d = abs(w[j].first - wt[i].first) + abs(w[j].second - wt[i].second);
            if (mp[wt[i]] == 0) {
                mp[wt[i]] = d;
                continue;
            }
            mp[wt[i]] = min(mp[wt[i]], d);
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(0, 0, v, visited, mp);
    cout << ans << edl;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}