#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(int r, int c, char c1, char c2, vector<string> &grid, int R, int C){
	if(r < 0 || r >= R) return 0;
	if(c < 0 || c >= C) return 0;
	
	if(grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for(int d = 0; d < 8; d++){
		ans += floodfill(r + dr[d], c + dc[d], c1, c2, grid, R, C);
	}
	return ans;
}
int main(){
	int m,n;
	while(cin>>m>>n){
		if(m == 0 && n == 0){
			break;
		}
		vector<string> arr(m);
		for(int i = 0; i < m; i++){
			cin>>arr[i];
		} 
		
		int ans = 0;
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				ans += ceil(floodfill(i, j, '@', '*', arr, m, n)/100.0);		
			}
		}
		cout<<ans<<endl;
		
	}
	
	
	
	return 0;
}