#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long int n;
    cin >> n;

    long long int ans = static_cast<long long>((sqrt(n * 8.0 + 1) - 1) / 2);
    cout << ans << endl;

    /*long long int m = ceil(ans);
    long long int k = floor(ans);

    (m > k) ? (cout << m << "\n") : cout << k << "\n";*/
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}