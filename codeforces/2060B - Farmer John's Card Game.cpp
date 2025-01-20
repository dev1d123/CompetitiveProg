#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define DBG_VEC(v) cerr << #v << ": ["; for (auto &x : v) cerr << x << " "; cerr << "]" << endl;
#define DBG_MAP(m) cerr << #m << ": {"; for (auto &[key, value] : m) cerr << key << ": " << value << ", "; cerr << "}" << endl;
#define RAYA cerr<<"=============================================================================="<<endl;

using namespace std;

bool compA(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
    return a.second[0] < b.second[0];   
}

int main(){
	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		vector<pair<int, vector<int>>> c(n);
		for(int i = 0; i < n; i++){
			vector<int> arr(m);
			for(int j = 0; j < m; j++){
				cin>>arr[j];
			}
			sort(arr.begin(), arr.end());
			c[i] = {i, arr};
		}
		sort(c.begin(), c.end(), compA);

		//comprobar!!!
		int card = 0;
		bool ans = true;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){	
				if(c[j].second[i] == card){
					card++;
				}else{
					ans = false;
				}
			}
		}
		if(!ans){
			cout<<-1<<endl;
		}else{
			for(auto p: c){
				cout<<p.first+1<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}