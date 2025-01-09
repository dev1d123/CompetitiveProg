#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	map<string, int> mapita;
	
	while(n--){
		string handle;
		int plus,minus,a,b,c,d,e;
		cin>>handle>>plus>>minus>>a>>b>>c>>d>>e;
		mapita[handle] = plus*100 - minus*50 + a + b + c+ d + e;
	}
	string ans;
	int index = numeric_limits<int>::min();
	for(auto pair: mapita){
		index = max(index, pair.second);
	}
	for(auto pair: mapita){
		if(pair.second == index){
			ans = pair.first;
			break;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}