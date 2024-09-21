#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
	if (a.second == b.second){ 
		return a.first < b.first;  
	}
	return a.second < b.second;
}
int countFactors(int n){
	if(n == 1) return 1;
	int ans = 0;
	for(int i = 2; i * i <= n; i++){
		while(n%i == 0){
			n /= i;
			ans++;
		}
		
	}
	if(n>1) {
		ans++;
	}
	return ans;
}
int main(){
	vector<pair<int, int>> ans(2000000 + 1, {0,0});
	for(int i = 1; i <= 2000000; i++){
		ans[i] = {i, countFactors(i)};
	}
	sort(ans.begin(), ans.end(), comp);
	int num;
	int c = 1; 
	while(cin>>num){
		if(num == 0) break;
		cout<<"Case "<<c++<<": "<<ans[num].first<<endl;
	}	
	return 0;
}