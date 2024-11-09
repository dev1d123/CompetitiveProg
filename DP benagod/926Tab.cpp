#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, xs, ys, xe, ye;
int W;
map<pair<int, int>, string> blocked;
vector<vector<int>> memo;

bool comp(string &s, char c){
	for(char ch: s){
		if(ch == c){
			return true;
		}
	}
	return false;
}
signed main(){
	int C;
	cin>>C;
	stringstream output;
	while(C--){
		//convertir todo a coordenadas trabajables
		cin>>N;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		memo.clear();

		xs = abs(N - b);
		ys = a - 1;
		
		xe = abs(N - d);
		ye = c - 1;
		if(xe > xs || ye < ys){
			cout<<0<<endl;
			continue;	
		}
		
		memo.assign(N, vector<int>(N, 0));
		blocked.clear();
		
		cin>>W;
		while(W--){
			int a,b;
			char dir;
			cin>>a>>b>>dir;
			int x = abs(N - b);
			int y = a - 1;
			blocked[{x, y}] += dir;
		}

		memo[xs][ys] = 1;
		for(int i = xs; i >= xe; i--){
			for(int j = ys; j <= ye; j++){
		
				int x = i;
				int y = j; 
				if(x != xs && !comp(blocked[{x+1, y}], 'N') && !comp(blocked[{x, y}], 'S')){
					memo[x][y]	+= memo[x + 1][y];
				}				
				if(j != ys && !comp(blocked[{x, y-1}], 'E') && !comp(blocked[{x, y}], 'W')){
					memo[x][y]	+= memo[x][y - 1];
				}
			}
		}
		output<<memo[xe][ye]<<endl;				
		
	}
	cout<<output.str();
	
	return 0;
}

