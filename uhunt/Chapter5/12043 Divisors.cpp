#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int, int> solve(int n){
	int numDiv = 0;
	int sumDiv = 0;
	for(int i = 1; i*i<=n;i++){
		if(n%i == 0){
			numDiv++;
			sumDiv+=i;
			if(i!= n/i){
				numDiv++;
				sumDiv += n/i;
			}
		}
	}
	return {numDiv, sumDiv};
}

signed main(){
	int t; cin>>t;
	stringstream output;
	while(t--){
		int a, b, k; 
		cin>>a>>b>>k; 		
		int ans1 = 0;
		int ans2 = 0;
		for(int i = a; i<=b; i++){
			if(i%k==0){
				auto [num, sum] = solve(i);
				ans1 += num;
				ans2 += sum;
			}
		}
		output<<ans1<<" "<<ans2<<endl;
	}
	cout<<output.str();
	return 0;
}