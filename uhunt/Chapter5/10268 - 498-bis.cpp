#include <bits/stdc++.h>
#define int long long
using namespace std;
int int_pow(int n, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= n;
        }
        n *= n;  
        exp /= 2;  
    }
    return result;
}
signed main(){
	int n;
	stringstream output;
	while(cin>>n){

		cin.ignore();
		string waos;
		getline(cin, waos);
		
		stringstream coef(waos);
		vector<int> nums;
		int number;
		while(coef>>number){
			nums.push_back(number);
		}	
		int c = nums.size();
		
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
			if(i == nums.size() - 1){
				continue;
			}
			ans += nums[i]*(c-i-1)*int_pow(n, c-i-2);
		}
		output<<ans<<endl;
	}
	cout<<output.str();
	
	return 0;
}