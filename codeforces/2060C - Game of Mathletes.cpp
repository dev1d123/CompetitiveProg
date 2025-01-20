#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define DBG_VEC(v) cerr << #v << ": ["; for (auto &x : v) cerr << x << " "; cerr << "]" << endl;
#define DBG_MAP(m) cerr << #m << ": {"; for (auto &[key, value] : m) cerr << key << ": " << value << ", "; cerr << "}" << endl;
#define RAYA cerr<<"=============================================================================="<<endl;

using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		vector<int> arr(n);
		map<int, int> elem;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			elem[arr[i]]++;
		}
		int ans = 0;
        for (int i = 0; i < n; i++) {
            int op = k - arr[i];
            if (elem[arr[i]] > 0 && elem[op] > 0) {
                if (arr[i] == op) {
                    if (elem[arr[i]] > 1) {
                        ans++;
                        elem[arr[i]] -= 2; 
                    }
                } else {
                    ans++;
                    elem[arr[i]]--;
                    elem[op]--;
                }
            }
        }
		cout<<ans<<endl;
		
	}
	
	return 0;
}