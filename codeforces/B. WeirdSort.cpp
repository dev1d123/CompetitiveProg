#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		vector<int> p(m);
		for(int i = 0; i < m; i++){
			cin>>p[i];
		}
		sort(p.begin(), p.end());
		int st = p[0];
		int f = p[0];
		for(int i = 1; i < m; i++){
			if(p[i] - st >= 2){
				f--;
				sort(a.begin() + f, a.begin() + st + 1);
				f = p[i]; 
			}else{
				//cout<<"sigue"<<endl;
				//siguen conectados
			}
			st = p[i];
		}
		
		//cout<<"no sigue -> ordenando "<<endl;
		f--;
		//cout<<"f: "<<f<<endl;
		//cout<<"st: "<<st<<endl;
		sort(a.begin() + f, a.begin() + st + 1);
		
		bool ans = true;
		for(int i = 0; i < n-1 ; i++){
			if(a[i] > a[i+1]){
				ans = false;
				break;
			}
		}		
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}