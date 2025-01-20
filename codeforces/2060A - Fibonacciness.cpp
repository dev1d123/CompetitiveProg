#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define DBG_VEC(v) cerr << #v << ": ["; for (auto &x : v) cerr << x << " "; cerr << "]" << endl;
#define DBG_MAP(m) cerr << #m << ": {"; for (auto &[key, value] : m) cerr << key << ": " << value << ", "; cerr << "}" << endl;
#define RAYA cerr<<"=============================================================================="<<endl;
using namespace std;

int solve(int a, int b, int c, int d, int e){
	int ans = 0;
	if(a+b==c)ans++;
	if(b+c==d)ans++;
	if(c+d==e)ans++;
	return ans;
}
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,d,e;
		cin>>a>>b>>d>>e;
		int ans = 0;
		for(int i = -500; i <= 500; i++){
			ans = max(ans, solve(a,b,i,d,e));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}