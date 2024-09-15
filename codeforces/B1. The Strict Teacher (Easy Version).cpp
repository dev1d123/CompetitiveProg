#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n, m, q;
		cin>>n>>m>>q;
		int b1, b2;
		cin>>b1>>b2;
		
		int d;
		cin>>d;
		
		int a, b;
		a = max(b1, b2);
		b = min(b1, b2);
		
		//si david esta entre dos profes
		if(b < d && d < a){
			if(d - b == a - d){
				cout<<a - d<<endl;
			}else{
				int dist1 = d - b;
				int dist2 = a - d;
				
				int minim = min(dist1, dist2);
				
				int maxim = max(dist1, dist2);
				
				
				
				cout<<minim + (maxim-minim)/2<<endl;
				
			}
		}else{
			
			if(b1 < d && b2 < d){
				int dist = 	abs(d - n);
				cout<<dist + min(abs(d-b1), abs(d-b2))<<endl;
			}else {
				int dist = 	abs(d - 1);
				cout<<dist + min(abs(d-b1), abs(d-b2))<<endl;;
			}
		}
		
		
	
	}

	
	
	return 0;
}