#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			int v; cin>>v;
			mp[v]++;
		}
		
		vector<int> arr;
		for(auto p: mp){
			int num = p.second;
			while(num >= 2){
				num-=2;
				arr.push_back(p.first);
			}
		}
		if(arr.size() < 4){
			cout<<"NO"<<endl;
			continue;
		}
		sort(arr.begin(), arr.end());
		int c = arr[arr.size() - 1];
		int d = arr[arr.size() - 2];
		int a = arr[0];
		int b = arr[1];
		cout<<"YES"<<endl;
		cout<<a<<" "<<b<<" "<<a<<" "<<c<<" "<<d<<" "<<b<<" "<<d<<" "<<c<<endl;
		
		
	}
	

	return 0;
}