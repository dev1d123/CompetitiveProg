#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	int m; cin>>m;
	vector<int> a(m);	
	for(int i = 0; i < m; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	string ans = s;
	
	for(int i = 0; i < m-1; i++){
		//poner el elemento a[i] -> a[i+1]
		int beg = a[i] - 1;
		int en = a[i+1] - 1;	
		if(i%2 == 0){
			for(int i = beg; i < en; i++){
				int inv = s.length() - 1 - i;
				swap(ans[i], ans[inv]);
			}	
		}
	}
	if(a.size()%2 == 1){
		int beg = a[m-1] - 1;
		int en = s.length()/2;
		for(int i = beg; i < en; i++){
			int inv = s.length() - 1 - i;
			swap(ans[i], ans[inv]);
		}
	}
	cout<<ans<<endl;
	return 0;
}