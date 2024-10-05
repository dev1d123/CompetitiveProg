#include <bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
}

void DFSRec(vector<string> &arr, vector<vector<int>> &valid, int x, int y, int & length, bool & isCycle, int &posCycle){
	//si se sale 
	if(x < 0 || y < 0 || x >= arr[0].size() || y >= arr.size()) return;
	if(valid[y][x]){
		posCycle = valid[y][x] - 1; //el nodo anterior
		isCycle = true;
		return;
	}
	length++;
	valid[y][x] = length;

	int newX = x, newY = y;
	if(arr[y][x] == 'W') newX--;
	if(arr[y][x] == 'S') newY++;
	if(arr[y][x] == 'E') newX++;
	if(arr[y][x] == 'N') newY--;

	DFSRec(arr, valid, newX, newY, length, isCycle, posCycle);
}

void DFS(vector<string> &arr, int x, int y){
	vector<vector<int>> valid(arr.size(), vector<int>(arr[0].size(), 0));

	bool isCycle = false;
	int length = 0;
	int posCycle = -1;
	
	DFSRec(arr, valid, x, y, length, isCycle, posCycle);
	
	if(isCycle){
		cout<<posCycle<<" step(s) before a loop of "<<length - posCycle<<" step(s)"<<endl;
	}else{
		cout<<length<<" step(s) to exit"<<endl;
		
	}
}

int main(){
	fastIO();
	int h, w, f;
	while(cin>>h>>w>>f){
		if(h == 0 && w == 0 && f == 0) break;
		vector<string> path(h);
		for(int i = 0; i < h; i++){
			 cin>>path[i];
		}
		
		DFS(path, f - 1, 0);
		
	}	
	return 0;
}