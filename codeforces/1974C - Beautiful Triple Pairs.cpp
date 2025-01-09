#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		map<pair<int, int>, int> mp1;
		map<pair<int, int>, int> mp2;
		map<pair<int, int>, int> mp3;
		map<tuple<int, int, int>, int> total;
		vector<tuple<int, int, int>> pairs;
		
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}	
		
		for(int i = 0; i < n - 2; i++){
			int a = arr[i];
			int b = arr[i+1];
			int c = arr[i+2];
			mp1[{b, c}]++;
			mp2[{a, c}]++;
			mp3[{a, b}]++;
			total[{a, b, c}]++;
			pairs.push_back({a, b, c});
		}
		int ans = 0;
		
		for(int i = 0; i < n - 2; i++){
			int a = arr[i];
			int b = arr[i+1];
			int c = arr[i+2];
			
			int to = total[{a, b, c}];
			int f = mp1[{b, c}];
			int s = mp2[{a, c}];
			int t = mp3[{a, b}];
			ans += f - to;
			ans += s - to;
			ans += t - to;
			total[{a,b,c}]--;
			mp1[{b, c}]--;
			mp2[{a, c}]--;
			mp3[{a, b}]--;
		}
		cout<<ans<<endl;
		
	
	}
	return 0;
}