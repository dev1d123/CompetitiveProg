#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define DBG_VEC(v) cerr << #v << ": ["; for (auto &x : v) cerr << x << " "; cerr << "]" << endl;
#define DBG_MAP(m) cerr << #m << ": {"; for (auto &[key, value] : m) cerr << key << ": " << value << ", "; cerr << "}" << endl;
#define RAYA cerr<<"=============================================================================="<<endl;

using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}		
		for(int i = 0; i < n-1; i++){
			int m = min(arr[i], arr[i+1]);
			arr[i] -=m;
			arr[i+1] -=m;
		}
		
		bool ans = true;
		for(int i = 0; i < n-1; i++){
			if(arr[i+1] < arr[i]){
				ans = false;
				break;
			}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}