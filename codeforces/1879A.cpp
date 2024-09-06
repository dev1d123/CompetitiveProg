#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> v;
		for(int i =0; i < n; i++){
			int s, e;
			cin>>s>>e;
			v.push_back(make_pair(s,e));
		}
		int w = v[0].first;
		int eW = v[0].second;
		bool polWin = true;
		for(int i = 1; i < n; i++){
			if(v[i].first >= w && v[i].second >= eW){
				polWin = false;
				break;
			}
		}
		if(polWin){
			cout<<w<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}