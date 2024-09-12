#include <bits/stdc++.h>
using namespace std;

int dr[] = {0,0, 1, -1};
int dc[] = {1, -1, 0, 0};

void floodfill(vector<string> &arr, int r, int c, int n, int m, bool color){
	if(r < 0 || r >= n) return;
	if(c < 0 || c >= m) return;
	
	if(arr[r][c] == '-') return;
	if(arr[r][c] == 'B' || arr[r][c] == 'W') return;
	
	if(color){
		arr[r][c] = 'W';
	}else{
		arr[r][c] = 'B';
	}
	color = !color;
	for(int i = 0; i < 4; i++){
		floodfill(arr, r + dr[i], c + dc[i], n,m, color);
	}
}
int main(){
	
	int n,m; cin>>n>>m;
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			floodfill(arr, i, j, n, m, true);
		}	
	}
	
	for(string &s: arr)
		cout<<s<<endl;	
	
	
	return 0;
}