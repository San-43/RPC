#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // dp_prev will hold the number of ways to reach cell i with a fixed number of jumps,
    // and dp_cur will be used to build the next layer (i.e. one additional jump).
    vector<int> dp_prev(n, 0), dp_cur(n, 0);
    long long ans = 0;

    // Base case: layer j = 0 (no jump moves are used, only steps).
    // The starting cell 0 is always empty and has exactly one way.
    dp_prev[0] = 1;
    for (int i = 1; i < n; i++){
        if (s[i] == '.') {
            // Only step moves are allowed when no jump is used.
            dp_prev[i] = dp_prev[i-1];
        } else {
            // Cannot step into a cactus.
            dp_prev[i] = 0;
        }
    }
    // A step move from the last cell gives a win.
    ans = (ans + dp_prev[n-1]) % MOD;

    // Now, for every additional jump we “layer” the DP.
    // In layer j (j >= 1) the states represent positions reached with exactly j jumps.
    // The new jump move is defined as follows:
    //   From a state at cell i with j-1 jumps, a jump lands on cell:
    //       pos = i + (j-1 + 2) = i + j + 1.
    // (Remember: the (j)th jump skips exactly j cells.)
    //
    // In addition, after a jump lands, step moves propagate the value to the right on contiguous empty cells.
    for (int j = 1; j < n; j++){
        // Clear the current layer.
        fill(dp_cur.begin(), dp_cur.end(), 0);

        // Build base values for the current layer from jump moves taken from the previous layer.
        for (int i = 0; i < n; i++){
            if(dp_prev[i] != 0){
                int pos = i + j + 1;  // jump landing: from dp_prev (layer j-1) the jump moves j+1 cells ahead.
                if(pos < n){
                    if(s[pos]=='.'){
                        dp_cur[pos] = (dp_cur[pos] + dp_prev[i]) % MOD;
                    }
                } else {
                    // If the jump lands past the end of the world, count it as a win.
                    ans = (ans + dp_prev[i]) % MOD;
                }
            }
        }

        // Now incorporate step moves within the same layer.
        // At each empty cell, you can step from the previous cell.
        for (int i = 1; i < n; i++){
            if(s[i]=='.'){
                dp_cur[i] = (dp_cur[i] + dp_cur[i-1]) % MOD;
            } else {
                // Reset if a cactus is encountered.
                dp_cur[i] = 0;
            }
        }

        // From the final (rightmost) cell in this layer, stepping off the board wins.
        ans = (ans + dp_cur[n-1]) % MOD;

        // If no state in the current layer reached any cell, we can stop early.
        bool nonZero = false;
        for (int i = 0; i < n; i++){
            if(dp_cur[i] != 0){
                nonZero = true;
                break;
            }
        }
        if(!nonZero)
            break;

        dp_prev.swap(dp_cur);
    }

    cout << ans % MOD << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}