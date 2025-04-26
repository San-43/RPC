#include <bits/stdc++.h>

using namespace std;

void solve() {
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    long long cnt[5] = {0, 0, 0, 0, 0};
    long long totalSum = 0;

    for (int i = 0; i < n; i++){
        double price;
        cin >> price;

        const int cents = static_cast<int>(round(price * 100));
        totalSum += cents;
        cnt[cents % 5]++;
    }

    long long discount = cnt[1] + cnt[2] * 2;

    const long long pairs = min(cnt[3], cnt[4]);
    discount += pairs * 2;


    const long long left3 = cnt[3] - pairs;
    discount += (left3 / 2) * 1;


    const long long left4 = cnt[4] - pairs;
    discount += (left4 / 3) * 2;

    cout << fixed << setprecision(2) << ((totalSum - discount) / 100.0) << "\n";
    return 0;

}