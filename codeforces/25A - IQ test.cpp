#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> arr(n);
	map<int, int> a1;
	map<int, int> a2;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(arr[i]%2 == 0){
			a1[i] = 1;
		}else{
			a2[i] = 1;
		}
	}
	if(a1.size() == 1){
		for(auto p: a1) cout<<p.first + 1;
	}else{
		for(auto p: a2) cout<<p.first + 1;
	}
	
	
	return 0;
}