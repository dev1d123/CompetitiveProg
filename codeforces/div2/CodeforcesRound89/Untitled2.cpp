#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	stringstream output;
	while(t--){
		string edge;
		vector<pair<char, char>> edges;
		while(cin>>edge && edge[0] != '*'){
			char c1 = edge[1];
			char c2 = edge[3];

			edges.push_back(make_pair(c1, c2));
		}
		int trees = 0;
		int acorn = 0;
		map<char, int> mp;
		map<char, int> count;
		
		for(auto p: edges){
			mp[p.first]++;
			mp[p.second]++;
			bool ishead = true;
			for(auto pair2: edges){
				if(p.first == pair2.second){
					ishead = false;
					break;
				}
			}
			if(ishead && count[p.first] == 0){
				count[p.first] = 1;
				trees++;
			}
		}
		string vx;
		cin>>vx;	
		for(int i = 0; i < vx.length(); i++){
			if(isalpha(vx[i])){
				if(mp[vx[i]] == 0){
					acorn++;
				}		
			}
		}
		output<<"There are "<<trees<<" tree(s) and "<<acorn<<" acorn(s)."<<endl; 
	}
	cout<<output.str();
	
	
	return 0;
}