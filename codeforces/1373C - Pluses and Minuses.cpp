#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		map<int, int> fm;
		
		set<int> used;
		
		int num = 0;
		int pos = 0;
		for(char c: s){
			if(c == '+'){
				num++;
			}else{
				num--;
			}
			pos++;
			if(!used.count(num)){
				used.insert(num);
				fm[num] = pos;
			}
		}
		int ans = 0;
		int i = 0;
		int compare = -(i + 1);
		while(fm.count(compare)){
			ans += fm[compare];
			i++;
			compare = -(i + 1);
		}
		ans += s.length();


		cout<<ans<<endl;
	}
	
	
	
	return 0;
}


