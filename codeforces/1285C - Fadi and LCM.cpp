#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int num;
	cin>>num;
	if(num == 1){
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	set<int> w;
	for(int i = 1; i*i <= num; i++){
		if(num%i == 0){
			w.insert(i);
			w.insert(num/i);
		}
	}
	vector<int> arr;
	for(int num: w){
		arr.emplace_back(num);
	}
	int ans = LLONG_MAX;
	int a, b;
	for(int i = 0; i < arr.size(); i++){
		int otro = num/arr[i];
		
        int lcm = (arr[i] * otro) / __gcd(arr[i], otro);
			
		if(lcm == num){
        	if (max(arr[i], otro) < ans) {
                ans = max(arr[i], otro);
				a = arr[i];
				b = otro;
			}
		}
	}
	cout<<a<<" "<<b<<endl;
}