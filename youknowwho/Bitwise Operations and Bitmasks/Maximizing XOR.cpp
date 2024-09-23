#include <bits/stdc++.h>
using namespace std;
int main(){
	int r, l; cin>>r>>l;
	int ans = 0;
	for(int i = r; i <= l; i++){
		for(int j = r; j <= i; j++){
			int XOR = i^j;
			ans = max(XOR, ans);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}