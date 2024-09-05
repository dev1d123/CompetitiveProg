#include <bits/stdc++.h>

using namespace std;
int dr[] = {1,0,-1, 0};
int dc[] = {0,1 ,0,-1};

bool alive(string &s){
	for(char c: s){
		if(c == 'x'){
			return true;
		}
	}
	return false;
}
int floodfill(int r, int c, vector<string> &grid, string &ship){
	if(r < 0 || r >= grid.size()) return 0;
	if(c < 0 || c >= grid[0].length()) return 0;

	if(grid[r][c] == '.') return 0;
	
	
	int ans = 1;
	ship += string(1, grid[r][c]);
	
	grid[r][c] = '.';
	for(int d = 0; d < 4; d++){
		ans += floodfill(r + dr[d], c+dc[d], grid, ship);
	}
	return ans;
}

int main(){
	int t; cin>>t;
	int c = 1;
	while(t--){
		int n; cin>>n;
		vector<string> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				string ship = "";
				int num = floodfill(i,j, arr, ship);
				if (num != 0){
					if(alive(ship)){
						ans++;	
					}
				}	
			}
		}
		cout<<"Case "<<c<<": "<<ans<<endl; 
		c++;
	}	
	return 0;
}