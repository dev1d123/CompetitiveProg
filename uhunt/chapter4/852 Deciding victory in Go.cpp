#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int floodfill(int r, int c, vector<string> &grid, bool &areBlack, bool &areWhite){
	if(r < 0 || r >= 9) return 0;
	if(c < 0 || c >= 9) return 0;
	
	if(grid[r][c] == '*'){
		//ya fue contado
		return 0;
	}
	
	if(grid[r][c] != '.'){
		//se topo con un color...
		if(grid[r][c] == 'O'){
			areWhite = true;
		}else{
			areBlack = true;
		}
		//ya no seguir...
		return 0;
	}
	//si es un puntito
	int ans = 1;
	grid[r][c] = '*';
	
	for(int i = 0; i < 4; i++){
		ans += floodfill(r + dr[i], c + dc[i], grid, areBlack, areWhite);
	}
	return ans;
}
int main(){
	int t = 0; cin>>t;
	while(t--){
		vector<string> arr(9);
		for(int i = 0; i < 9; i++){
			cin>>arr[i];
		}
		
		int black = 0;
		int white = 0;
		
		int blackT = 0;
		int whiteT = 0;
		for(int i = 0; i < 9; i++){
			for(int j = 0 ; j < 9; j++){
				if(arr[i][j] == 'O'){
					white++;
				}else if(arr[i][j] == 'X'){ 
					black++;
				}else{
					bool areBlack = false;
					bool areWhite = false;
					
					int ans = floodfill(i, j, arr, areBlack, areWhite);
					if(areBlack && areWhite){
						//nada
					}else if(areBlack){
						blackT += ans;
					}else if(areWhite){
						whiteT += ans;
					}
				}
			}
		}
		cout<<"Black "<<black+blackT<<" White "<<white+whiteT<<endl;
	}
	
	
	
	return 0;
}