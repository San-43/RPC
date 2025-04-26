#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    long long r = 0;
    for(int i =0; i < n; i++) {
        cin>>v[i];
        r = max(r, v[i]);
    }

    long long l = 1;
    while (l < r) {
        long long mid = l+ (r - l) / 2;
        bool ok = true;
        long long tmp = 0;
        for(auto i : v) {
            tmp += (i + mid - 1) / mid;
            if ( tmp > k) {
                ok = false;
                break;
            }
        }
        if(ok)
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << '\n';
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