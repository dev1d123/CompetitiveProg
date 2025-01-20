#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int ans = 4*m*n;
		int xi, yi;
		cin>>xi>>yi;
		
		for(int i = 0; i < n-1; i++){
			int x, y; cin>>x>>y;
			int xa = xi+x;
			int ya = yi+y;

			int d1 = xi + m - xa;
			int d2 = yi + m - ya;

			int diff = 2*(d1+d2);
			ans -= diff;
			//ans += 4*n;
			xi = xa;	
			yi = ya;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}