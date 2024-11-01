#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	//fijar el maximo elemento...
	int ans = 0;
	int p = a[n - 1];
	ans += abs(p - n);
	a[n - 1] = n;
	
	int c = n - 1;
	for(int i = n - 2; i >= 0; i--){
		ans += abs(a[i] - c);
		c--;
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}