#include <bits/stdc++.h>

using namespace std;

void solve() {
    int g, r;
    cin >> g >> r;
    long long sum = 0;
    while(g > 0 && r > 0) {
        sum += 10;
        g--;
        r--;
    }
    while (g >= 3) {
        sum +=10;
        g-=3;
    }
    if (g == 2) {
        sum += 3;
    } else if (g == 1) {
        sum += 1;
    }

    cout << sum << '\n';
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