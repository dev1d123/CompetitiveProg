#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kMoves = {
	{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isValid(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int BFSKnight(pair<int, int> &x, pair<int, int> &y){
	if(x.first == y.first && x.second == y.second){
		return 0;
	}
	queue<pair<pair<int, int>, int>> q; // -> position and moves
	vector<vector<bool>> vis(8, vector<bool>(8, false));
	
	q.push({x, 0});
	vis[x.first][x.second] = true;
	while(!q.empty()){
		auto [act, moves] = q.front();
		q.pop();
		for(auto m: kMoves){
			int newX = act.first + m.first;
			int newY = act.second + m.second;
			
			if(newX == y.first && newY ==y.second){
				return moves + 1;
			}
			if(isValid(newX, newY) && !vis[newX][newY]){
				vis[newX][newY] = true;
				q.push({{newX, newY}, moves + 1});
			}
		}
	}
}

int main(){
	string m1, m2;
	while(cin>>m1>>m2){
		pair<int, int> x = {(m1[0] - 'a'), (m1[1] - '1')};
		pair<int, int> y = {(m2[0] - 'a'), (m2[1] - '1')};
		int ans = BFSKnight(x, y);
		cout<<"To get from "<<m1<<" to "<<m2<<" takes "<<ans<<" knight moves."<<endl;
	}
	
	return 0;
}