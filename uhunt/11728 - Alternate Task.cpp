#include <bits/stdc++.h>
using namespace std;
int sumDiv(int n){
	if(n == 1) return 1;
	int ans = n+1; // count the 1 + the same number
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			ans += i;
			if(i != 1 && n/i != i){
				ans += n/i;
			}
		}
	}
	return ans;

}
int main(){
	int n;
	int c = 1;
	while(cin>>n){
		if(n==0) break;
		int ans = -1;
		for(int i = 1; i <= 1000; i++){
			if(sumDiv(i) == n){
				ans = max(ans, i);
			}
		}
		cout<<"Case "<<c<<": "<<ans<<endl;
		c++;
	}
	
	
}