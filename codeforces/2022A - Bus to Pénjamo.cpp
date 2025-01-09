#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, r; cin>>n>>r;
		int sum = 0;
		int happy = 0;
		int solo = 0;
		int dis = 0; 
		for(int i = 0; i < n; i++){
			int v; cin>>v;
			sum += v;
			if(v%2 == 0){
				happy+=v;;
				dis += v/2;
			}else{
				if(v != 1){
					v--;
					happy += v;
					dis += v/2;
				}
				solo++;
			}
		}
		int ans = 0;
		int dispo = r - dis;
		
		while(solo > 0 && dispo > 0){
			solo--;
			dispo--;
			ans++;
		}
		
		cout<<happy + ans-solo<<endl;
	}
		
	
	
	return 0;
}