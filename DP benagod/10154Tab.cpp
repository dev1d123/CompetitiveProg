#include <bits/stdc++.h>
using namespace std;

struct Turtle {
    int weight;
    int strength;
};

bool compareTurtles(const Turtle &a, const Turtle &b) {
    return a.strength < b.strength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Turtle> turtles;
    int weight, strength;

    while (cin >> weight >> strength) {
        turtles.push_back({weight, strength});
    }

    sort(turtles.begin(), turtles.end(), compareTurtles);

    int n = turtles.size();
    const int INF = 1e9;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;  

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            dp[i][k] = dp[i-1][k]; //ignorar
            
            if (k > 0 && dp[i-1][k-1] + turtles[i-1].weight <= turtles[i-1].strength) {
                dp[i][k] = min(dp[i][k], dp[i-1][k-1] + turtles[i-1].weight); //incluir
            }
        }
    }

    int maxTurtles = 0;
    for (int k = 0; k <= n; k++) {
        if (dp[n][k] < INF) {
            maxTurtles = k;
        }
    }

    cout << maxTurtles << endl;

    return 0;
}
