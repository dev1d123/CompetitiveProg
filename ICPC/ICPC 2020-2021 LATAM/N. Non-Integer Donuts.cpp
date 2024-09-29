#include <bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
int getCent(string &s){
	size_t dotPos = s.find('.');
	return stoi(s.substr(dotPos + 1));
}
int main(){
	fastIO();
	int n; cin>>n;
	string s; cin>>s;
	int f = getCent(s);
	int ans = 0;
	while(n--){
		cin>>s;
		int ac = getCent(s);
		
		f += ac;
		
        if(f%100 != 0){ 
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}