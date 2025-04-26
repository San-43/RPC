#include <bits/stdc++.h>

using namespace std;

void dfs(const int node, vector<vector<int>>& adj, vector<bool>& visited, long long& count) {
    visited[node] = true;
    ++count;
    for (const int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, count);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            long long count = 0;
            dfs(i, v, visited, count);
            ans += count * (count - 1LL) / 2;
        }
    }
    cout << ans - m << endl;

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}