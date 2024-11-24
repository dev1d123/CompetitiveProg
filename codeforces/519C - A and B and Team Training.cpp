#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m; cin>>n>>m;
	int ans = 0;
	if(n < m){
		while((n > 0 && m > 0) && n != m){
			ans++;
			n--;
			m-=2;
		}
	}else if(n > m){
		while((n > 0 && m > 0) && n != m){
			ans++;
			n-=2;
			m--;
		}
	}
	if(n == m){
		ans += ((n + m) - (n + m)%3)/3;
	}
	cout<<ans<<endl;	
	return 0;
}