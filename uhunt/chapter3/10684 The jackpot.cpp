#include <bits/stdc++.h>
using namespace std;

//kadane algorithm!
int main(){
	int n;
	stringstream output;
	while(cin>>n){
		if(n == 0) break;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int sum = 0, ans=0;
		
		for(int i = 0; i < n; i++){
			sum += arr[i];
			ans = max(ans, sum);
			if(sum < 0) sum = 0;
		}
		
		if(sum != 0) output<<"The maximum winning streak is "<<ans<<"."<<endl;
		else output<<"Losing streak."<<endl;	
		
		
	}
	cout<<output.str();
	
	return 0;
}