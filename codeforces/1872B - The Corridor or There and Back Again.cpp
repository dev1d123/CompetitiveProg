#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		map<int, int> tr;
		
		for(int i = 0; i < n; i++){
			int d, s; cin>>d>>s;
			if(tr[d] != 0){
				tr[d] = min(tr[d], s);
			}else{
				tr[d] = s;
			}
		}
		
		int ans = 0;
		int time = INT_MAX;
		bool traped = false;
		
		for(int i = 0; i <= 1000; i++){
			if(traped){
				time -= 2;	
			}
			if(time <= 0){
				ans = i;
				break;
			}
			if(tr[i+1] != 0){
				traped = true;
				time = min(time, tr[i+1]);
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}