#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k; cin>>n>>k;
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		arr[i] = {x, i};
	}
	sort(arr.begin(), arr.end());
	int ans  = INT_MAX;
	set<int> w;

	for(int i = 0; i < n; i++){
		w.insert(arr[i].second);
		if(i >= k - 1){
			int mi = *w.begin();
			int ma = *w.rbegin();
			ans = min(ans, ma-mi);
			w.erase(arr[i-k+1].second);
		}
	
	}
	cout<<ans<<endl;

	return 0;	
}
