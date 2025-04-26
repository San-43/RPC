#include <bits/stdc++.h>

using namespace std;

void solve() {

}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int> v(t);
    vector<int> n(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i] >> n[i];
    }
    if (is_sorted(v.begin(), v.end())) {
        if (is_sorted(n.begin(), n.end())) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    } else {
        cout << "no\n";
    }

    return 0;
}