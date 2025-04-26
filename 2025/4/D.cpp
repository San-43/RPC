#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int num = 2*n;
    vector<int> a;
    vector<int> b;
    vector<int> v(num+5, 0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
        a.push_back(x);
    }

    for (int i = 1; i <= n * 2; i++) {
        if (!v[i]) {
            b.push_back(i);
        }
    }
    sort(a.begin(), a.end());

    int j = 0;
    int maxa = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] > b[j]) {
            maxa++;
            j++;
        }
    }

    j = 0;
    int maxb = 0;
    for (int i = 0; i < n; i++) {
        if(b[i] > a[j]) {
            maxb++;
            j++;
        }
    }


    cout<< n - maxb << " " << maxa << '\n';
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