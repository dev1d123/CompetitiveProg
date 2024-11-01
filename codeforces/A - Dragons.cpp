#include <bits/stdc++.h>
using namespace std;
int main(){
	int s, n;
	cin>>s>>n;
	vector<pair<int,int>>game;
	for(int i = 0 ; i < n; i++){
		int a,b;
		cin>>a>>b;
		game.push_back(make_pair(a,b));
	}
	sort(game.begin(), game.end());
	//game
	for(auto dragon:game){
		if(s > dragon.first){
			s+=dragon.second;
		} else{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}