    #include<bits/stdc++.h>
    using namespace std;
     
    char a[51][51];
    int n, m;
     
    void dfs(int x, int y) {
    	a[x][y] = '.';
     
    	int nx, ny;
    	nx = x + 1, ny = y;
    	if (nx > n || a[nx][ny] != '.') a[x][y] = '*';
    	else dfs(nx, ny);
    }
     
     
    void solve() {
    	cin >> n >> m;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) cin >> a[i][j];
    	}
     
    	for (int i = n; i >= 1; i--) {
    		for (int j = 1; j <= m; j++) {
    			if (a[i][j] == '*') dfs(i, j);
    		}
    	}
     
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) cout << a[i][j];
    		cout << endl;
    	}
    	cout << endl;
    }
    int main() {
    	int t = 1;
    	cin >> t;
    	while (t--) {
    		solve();
    	}
    }


