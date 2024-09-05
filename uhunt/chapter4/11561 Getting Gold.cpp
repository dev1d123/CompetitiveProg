#include <bits/stdc++.h>
using namespace std;
	
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
void gamefill(int r, int c, vector<string> &arr, int h, int w, int &ans){
	if(r < 0 || r >= h) return;
	if(c < 0 || c >= w) return;
	
	if(arr[r][c] == '#'){
		return;
	}
	
	if(arr[r][c] == 'G'){
		ans++;
	}
	
	arr[r][c] = '#'; 
	
	//si percibe una trampa es el final de la ruta!
	if(arr[r+1][c] == 'T' || arr[r][c+1] == 'T' || arr[r-1][c] == 'T' || arr[r][c-1] == 'T'){
		return;
	}
	
	
	for(int i = 0; i < 4; i++){
		gamefill(r + dr[i], c+dc[i], arr, h, w, ans);
	}
	
}

int main(){
	int w, h;
	while(cin>>w>>h){
		vector<string> arr(h);
		for(int i = 0; i < h; i++){
			cin>>arr[i];
		} 
		
		//find ubication of p
		int x = -1;
		int y = -1;
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(arr[i][j] == 'P'){
					x = i;
					y = j;
					break;
				}
			}
			if(x!=-1) break;	
		}
	
		int ans = 0;
		gamefill(x, y, arr, h, w, ans);
		cout<<ans<<endl;

		
	}
	
	
	
	return 0;
}