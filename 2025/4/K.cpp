#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< m; j++) {
            cin >> g[i][j];
            sum += g[i][j];
        }
    }

    int s, t;
    cin >> s >> t;
    vector<pair<int,int>> land;
    for(int i = 0; i < s; i++) {
        for(int j =0; j < t; j++) {
            char c;
            cin >> c;
            if (c == '#')
                land.emplace_back(i, j);

        }
    }

    long long ans = LLONG_MAX;

    for (int rot = 0; rot < 4; rot++) {
        for (int i = 0; i + s <= n; i++) {
            for (int j = 0; j + t <= m; j++) {
                long long tmp = 0;
                for (auto &p : land) {
                    tmp += g[i + p.first][j + p.second];
                    if (tmp >= ans) break;
                }
                ans = min(ans, tmp);
            }
        }
        vector<pair<int,int>> next;

        for (auto &p : land) {
            next.emplace_back(p.second, s - 1 - p.first);
        }
        land.swap(next);
        swap(s, t);
    }
    cout << sum - ans << '\n';
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