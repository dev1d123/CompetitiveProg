#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> col, colors;
int ans = 0;

void paint(int s, int c) {
    col[s] = c;
    for (int i : adj[s]) {
        paint(i, c); 
    }
}

void dfsCol(int s) {
    if (col[s] != colors[s]) {
        ans++;
        paint(s, colors[s]);
    }

    for (int i : adj[s]) {
        dfsCol(i);
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n);
    col.resize(n);
    colors.resize(n);
    
    for (int i = 0; i < n; i++) {
        col[i] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        int u;
        cin >> u;
        u--; 
        adj[u].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    dfsCol(0);

    cout << ans << endl;

    return 0;
}
