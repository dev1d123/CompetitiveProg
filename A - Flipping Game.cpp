#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> arr(n);
	vector<int> dp0(n+1, 0);	
	vector<int> dp1(n+1, 0);
	for(int i = 1; i <= n; i++){
		int elem; cin>>elem;
		if(elem == 0) dp0[i] = dp0[i-1] + 1;
		else dp0[i] = dp0[i-1];
		
		if(elem == 1) dp1[i] = dp1[i-1] + 1;
		else dp1[i] = dp1[i-1];
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			int ceros = dp0[i] - dp0[j-1];
			//unos restantes y unos posteriores...xd 
			int resto = 0;
			resto += dp1[n] - dp1[i]; 
			resto += dp1[j-1]; 
			ans = max(ans, resto + ceros);
		}
	}
	cout<<ans<<endl;
	return 0;
}