#include <bits/stdc++.h>

using namespace std;

void solve() {
    pair<int, int> p1;
    pair<int,int> p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    
    set<pair<int,int>> p;
    p.insert({0, 0});
    p.insert({2024,0});
    p.insert({2024, 2024});
    p.insert({0, 2024});

    int count = 0;
    if (p.count(p1))
        count++;
    if(p.count(p2))
        count++;
    
    if (count == 0)
        cout << "2\n";
    else if (count == 1)
        cout << "1\n";
    else 
        cout << 0 << endl;

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