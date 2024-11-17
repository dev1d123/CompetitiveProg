#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<bool>> obs;

vector<pair<int, int>> kMoves = {
	{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

vector<pair<int, int>> kbMoves = {
	{-2, -2}, {2, 2}, {-2, 2}, {2, -2}
};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !obs[x][y];
}
 


int anything(int xs, int ys, int xe, int ye){
	if(xs == xe && ys == ye){
		return 0;
	}
	queue<pair<pair<int, int>, pair<int, int>>> q; // -> position, moves, lastMove
	//lastMove 1 -> knight,
	//lastMove 2 -> bishop,
	//LastMove 3 -> simetrical
	
    vector<vector<vector<bool>>> vis(N, vector<vector<bool>>(N, vector<bool>(4, false)));

	q.push({{xs,ys}, {0, 0}});
	while(!q.empty()){
		auto [act, mov] = q.front();
		q.pop();
		if(mov.second != 1){
			
			for(auto m: kMoves){
				int newX = act.first + m.first;
				int newY = act.second + m.second;
				
				if(newX == xe && newY ==ye){
					return mov.first + 1;	
				}
				if(isValid(newX, newY) && !vis[newX][newY][1]){
					vis[newX][newY][1] = true;
					q.push({{newX, newY}, {mov.first + 1, 1}});
				}
			}
		}
		if(mov.second != 2){
			for(auto m: kbMoves){
				int newX = act.first + m.first;
				int newY = act.second + m.second;
				
				if(newX == xe && newY == ye){
					return mov.first + 1;
				}
				if(isValid(newX, newY) && !vis[newX][newY][2]){
					vis[newX][newY][2] = true;
					q.push({{newX, newY}, {mov.first + 1, 2}});
				}
			}
		}
		if(mov.second != 3){
			//simetrico x
			int newX = N - act.first - 1;
			int newY = act.second;
			if(newX == xe && newY == ye){
				return mov.first + 1;
			}
			if(isValid(newX, newY) && !vis[newX][newY][3]){
				vis[newX][newY][3] = true;
				q.push({{newX, newY}, {mov.first + 1, 3}});
			}
		
			newX = act.first;
			newY = N - act.second - 1;
			
			if(newX == xe && newY ==ye){
				return mov.first + 1;
			}
			if(isValid(newX, newY) && !vis[newX][newY][3]){
				vis[newX][newY][3] = true;
				q.push({{newX, newY}, {mov.first + 1, 3}});
			}
		}

	}
	return -1;
}

int main(){
	while(cin>>N){
		if(N == 0) return 0;
		N = N*2;
		obs.clear();
		obs.assign(N, vector<bool>(N, false));
		int xs, ys;
		int xe, ye;
		cin>>xs>>ys>>xe>>ye;
		xs--;
		ys--;
		xe--;
		ye--;
		int xo, yo;
		while(cin>>xo>>yo){
			if(xo == 0 && yo == 0){
				break;
			}
			xo--;yo--;
			obs[xo][yo] = true;
		}
		//do whatever
		int ans = anything(xs, ys, xe, ye);
		if(ans != -1){
			cout<<"Result : "<<ans<<endl;
		}else{
			cout<<"Solution doesn't exist"<<endl;
		}
	}
	
	
	
	return 0;
}