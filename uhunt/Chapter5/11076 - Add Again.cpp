#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int powLL(int base, int exp) {
    int result = 1;
    int x = base;
    int n = exp;
    if (n < 0) {
        return 0;  
    }
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;  
        n /= 2;  
    }
    return result;
}
int fact(int n){
	if(n == 0) return 1;
	return n*fact(n-1);
}
int calc(vector<int> &arr, int num){
	map<int, int> mp;
	for(int n: arr){
		mp[n]++;
	} 
	mp[num]--;
	
	int pr = fact(arr.size() - 1);
	
	int div = 1;
	for(auto p: mp){	
		div *= fact(p.second);
	}
	return pr/div;
}
signed main(){
	int n; 
	stringstream output;
	while(cin>>n){
		if(n == 0) break;
		vector<int> arr(n);
		set<int> s;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			s.insert(arr[i]);
		}
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			for(int num: s){
				ans += num*powLL(10, i)*calc(arr, num);
			}
		}
		cout<<ans<<endl;
	}
	//bro...i dont read the unsigned ll 
	return 0;
}