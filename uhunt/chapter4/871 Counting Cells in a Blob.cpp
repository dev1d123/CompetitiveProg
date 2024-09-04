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
		ans += floodfill(r + dr[d], c + dc[d], c1 ,c2, grid, R, C);
	}
	return ans;
	
}
int main(){
	int t; 
	cin>>t;
	t++;
	int xd = t;
	cin.ignore();
	vector<string> arr;
	stringstream output;
	while(true){
		string data;
		getline(cin, data);
		if(data == ""){
			
			int ans = 0;
			for(int i = 0; i < arr.size(); i++){
				for(int j = 0; j < arr[i].size(); j++){
					ans = max(ans, floodfill(i, j, '1', '0', arr, arr.size(), arr[i].size()));
				}
			}
			t--;
			if(xd != t+1){
				output<<ans<<endl;
				if(t == 0){
					break;
				}
				output<<endl;
			}
			
			arr.clear();
		}else{
			arr.push_back(data);
		}
	}
	cout<<output.str();
	return 0;
}