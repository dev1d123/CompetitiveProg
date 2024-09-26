#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr){
	int res = arr[0];
	int ans = 0;
	for(int i = 0; i < arr.size(); i++){
		arr[i] -= res;	
		ans = __gcd(ans, arr[i]);
	}
	return abs(ans);
	//the prof can be a little complicated
	//if the answer is eventually reached, it is possible to modify the residue to any value 
	//depending on the value of arr[0], then just subtract this value from all and then find the gcd.
	//i forgot....the divisor always is positive
}

int main(){
	int num;
	vector<int> arr;
	while(cin>>num){
		if(arr.size() == 0 && num == 0) break;
		if(num == 0){
			int ans = solve(arr);
			cout<<ans<<endl;
			arr.clear();
		}else{
			arr.push_back(num);	
		}
	}
	
	return 0;
}