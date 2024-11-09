#include <bits/stdc++.h>
using namespace std;
string bigSum(string a, string b) {
    if (a.length() > b.length()) {
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result = "";
    int carry = 0;
    int n = a.length();

    for (int i = 0; i < n; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n; i < b.length(); i++) {
        int sum = (b[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}
int main(){
	vector<string> dp(251);
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
 	for(int i = 3; i <= 250; i++){
		dp[i] = bigSum(dp[i-1], bigSum(dp[i - 2], dp[i - 2]));
	}
	int n; 
	stringstream output;
	while(cin>>n){
		output<<dp[n]<<endl;
	}
	cout<<output.str();
	
	return 0;
}
