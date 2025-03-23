#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin>>n;
	vector<pair<int, int>> arr(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		arr[i] = {a,b};
		sum += a;		
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int temp = sum - arr[i].first + arr[i].second;
		ans = max(temp, ans);
	}
	cout<<ans<<endl;
}
