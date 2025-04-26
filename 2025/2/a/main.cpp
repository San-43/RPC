#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Team {
    int id;
    int score;
    int pending;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    const int favori = r - 1;

    vector<Team> teams(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        int score = 0, pending = 0;
        for (char c : s) {
            if (c == 'A') score++;
            if (c == 'P') pending++;
        }
        teams[i] = {i, score, pending};
    }

    vector<Team> rank = teams;

    int total = 0;
    for (int i = 0; i < n; i++){
        total += teams[i].pending;
    }

    for (int k = 0; k < total; k++){
        int pos = -1;

        for (int i = rank.size() - 1; i >= 0; i--){
            if (rank[i].pending > 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) break;

        rank[pos].pending--;

        string a, b;
        cin >> a >> b;

        if (b[3] == 'w') {
            continue;
        }
        int count = 0;
        for (const char c : b) {
            if (c == 'y') count++;
        }

        count -= 3;

        rank[pos].score++;

        const int newPos = max(0, pos - count);
        Team team = rank[pos];
        rank.erase(rank.begin() + pos);
        rank.insert(rank.begin() + newPos, team);
    }

    int final_rank = 0;
    for (int i = 0; i < rank.size(); i++){
        if (rank[i].id == favori) {
            final_rank = i + 1;
            break;
        }
    }
    cout << final_rank << "\n";

    return 0;
}
