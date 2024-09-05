#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> moves;

void DFS(vector<vector<int>> &arr, int x, int y, int r, int c, vector<vector<bool>> &visited){
    if (x < 0 || x >= r || y < 0 || y >= c || arr[x][y] == -1 || visited[x][y]) return;
    visited[x][y] = true; 
	
	set<pair<int, int>> mov;
	for(auto p: moves){
		int mx = x + p.first;
		int my = y + p.second;
		if(mx >= 0 && mx < r && my >= 0 && my < c && arr[mx][my] != -1){
			mov.insert({mx, my});
		}
	}
	arr[x][y] = mov.size();
	
	
	for(auto p: mov){
      if (!visited[p.first][p.second]) {
            DFS(arr, p.first, p.second, r, c, visited);
        }	
	}
	
	
}
int main(){
	int t; cin>>t;
	int waos = 1;
	while(t--){
		moves.clear();
		int r,c,m,n;
		cin>>r>>c>>m>>n;
		vector<vector<int>> arr(r, vector<int>(c, -2));
		/*
		-2 -> all the grids...(are always -2 if they have not been visited)
		-1 -> water
		*/
		
		//necesary to avoid infinite stack recursion....(DFS no need to repeat nodes)
		vector<vector<bool>> visited(r, vector<bool>(c, false));

		moves = { {-n, -m}, {-n, m}, {n, -m}, {n, m}, {-m, -n}, {-m, n}, {m, -n}, {m, n} };
		
		
		int w; cin>>w;
		for(int i = 0; i < w; i++){
			int a, b;
			cin>>a>>b;
			arr[a][b] = -1;
		}
		
		int even = 0;
		int odd = 0;
		

		
		DFS(arr, 0, 0, r, c, visited);
		
		//just count
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c;j++){
				if(arr[i][j] == -1 || arr[i][j] == -2) continue;
				
				if(arr[i][j]%2 == 0){
					even++;
				}else{
					odd++;
				}
			}
		}
		cout<<"Case "<<waos<<": "<<even<<" "<<odd<<endl;
		waos++;
		
		
	}
	
	
	
	return 0;
}