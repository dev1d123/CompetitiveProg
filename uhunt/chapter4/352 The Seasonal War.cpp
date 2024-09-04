#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int floodfill(int r, int c, char c1, char c2, vector<string> &grid, int m){
	if(r < 0 || r >= m) return 0;
	if(c < 0 || c >= m) return 0;

	if(grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for(int d = 0; d < 8; d++){
		ans += floodfill(r + dr[d], c + dc[d], c1 ,c2, grid, m);
	}
	return ans;
	
}
int main(){

	int n;
	int c = 1;
	stringstream output;
	while(cin>>n){
	
		vector<string> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(floodfill(i, j, '1', '0', arr, n) != 0){
					ans++;
				}
			}
		}
		output<<"Image number "<<c<<" contains "<<ans<<" war eagles."<<endl;
		c++;
	}	
	
	cout<<output.str();
	
	return 0;
}