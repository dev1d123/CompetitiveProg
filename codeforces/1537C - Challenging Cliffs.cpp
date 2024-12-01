#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> mt(n);
		for(int i = 0; i < n; i++){
			cin>>mt[i];
		}
		sort(mt.begin(), mt.end());
		
		if(n==2){
			cout<<mt[0]<<" "<<mt[1]<<endl;
			continue;
		}
		
		int minDiff = INT_MAX;
		int pos=-1;
		
		for(int i = 1; i < n; i++){
			if(minDiff > (abs(mt[i] - mt[i-1]))){
				minDiff = abs(mt[i] - mt[i-1]);
				pos=i;
			}			
		}
		
		for(int i=pos; i <n; i++){
			cout<<mt[i]<<" ";
		}	
		for(int i=0; i < pos; i++){
			cout<<mt[i]<<" ";
		}		
		
		cout<<endl;
		
	}


}