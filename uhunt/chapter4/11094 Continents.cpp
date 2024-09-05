#include <bits/stdc++.h>
using namespace std;

int dc[] = {0, 0, 1, -1};
int dr[] = {1, -1, 0, 0};
int floodfill(int r, int c, vector<string> &grid, char c1, char c2, int m, int n){
	if(r < 0 || r >= m) return 0;
	//if(c < 0 || c >= n) return 0;
	
	//if(r < 0) r = m-1;
	//if(r >= m) r = 0;
	if(c < 0) c = n-1;
	if(c >= n) c = 0;
	
	if(grid[r][c] != c1) return 0;
	
	int ans = 1;
	
	grid[r][c] = c2;
	
	for(int i = 0 ; i < 4; i++){
		ans += floodfill(r + dr[i], c + dc[i], grid, c1, c2 ,m, n);
	}
	return ans;
}
int main(){
	int m,n; 
	stringstream output;
	while(cin>>m>>n){
		vector<string> grid(m);
		for(int i = 0; i < m; i++){
			cin>>grid[i];
		}
		
		int x,y;
		cin>>x>>y;
		char land = grid[x][y];
		
		
		char water = grid[x][y];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] != land){
					water = grid[i][j];
					break; 
				}
			}
		}
		if(water == land) water = land + 1;
		
	
		int waos = floodfill(x,y, grid, land,water, m,n);
		int ans = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				ans = max(ans, floodfill(i,j,grid, land, water, m, n));
			}
		}
		output<<ans<<endl;
	}
	cout<<output.str();
	
	return 0;
}