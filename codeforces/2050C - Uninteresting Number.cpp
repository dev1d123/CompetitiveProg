#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
bool solve(int res, vector<int> &nums, int idx, int sum){
	int modSum = (sum%9 + 9)%9;
	if(memo[idx][modSum] != -1){
		return memo[idx][modSum];
	}
	
	if(idx == nums.size()){
		return memo[idx][modSum] = ((sum - res) % 9 == 0);
	}
	
	if((sum-res)%9 == 0){
		return memo[idx][modSum] = true;
	}
	bool result = solve(res, nums, idx + 1, sum) || solve(res, nums, idx + 1, sum + nums[idx]);
    return memo[idx][modSum] = result;
}

int main(){
	int t; cin>>t;
	while(t--){
		string n; cin>>n;
		int sum = 0;
		vector<int> nums;
		for(char ch: n){
			sum += (ch - '0');
			if(ch == '2'){
				nums.emplace_back(2);
			}else if(ch == '3'){
				nums.emplace_back(6);
			}
		}
		
		int sig = sum/9.0  + 1 ;
		if(sum%9 == 0){
			cout<<"YES"<<endl;
		}else{
			int res = (ceil(sig) * 9) - sum;
			memo.assign(nums.size() + 1, vector<int>(9, -1));
			bool pos = solve(res, nums, 0, 0);
			if(pos){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
	
		}
	}	
}