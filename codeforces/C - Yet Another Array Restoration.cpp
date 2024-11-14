#include <bits/stdc++.h>
using namespace std;


void solve(int n, int x, int y, int &a1, int& r){
	int minan = INT_MAX;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			//si x es aj
			//si y es ai
			
			if((y-x)%(i-j) == 0){
				int d =	(y - x)/(i-j);
				int temp = x - (j * d);
				if(temp <= 0) continue;
				int an = temp + (n - 1) * d;
				if(an < minan){
					minan = an;
					a1 = temp;
					r = d;
				} 		
			}
		}
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int n, x, y; cin>>n>>x>>y;
		int a1, r;
		solve(n, x, y, a1, r);
		for(int i = 0; i < n; i++){
			cout<<a1 + r*i<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}