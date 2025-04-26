#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<bool> visited(n + 2, false);
    int ans = 0;
    int tmp = 1;
    while (!visited[tmp]) {
        visited[tmp] = true;
        tmp = v[tmp];
        ans++;
    }
    cout << ans << endl;
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