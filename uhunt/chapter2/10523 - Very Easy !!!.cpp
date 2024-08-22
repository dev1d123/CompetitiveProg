#include <bits/stdc++.h>
using namespace std;

string bigIntegerSum(string s1, string s2){
    string a=s2, b=s1;
    if(s1.length() >= s2.length()){
        a=s1;
        b=s2;
    }
    string ans = "";
    int idx1 = a.length() - 1;
    int idx2 = b.length() - 1;
    int carry = 0;
    for(int i = 0; i < a.length(); i++){
        int digitA = a[idx1] - '0';  
        int digitB = idx2 >= 0 ? b[idx2] - '0' : 0; 
        int res = digitA + digitB + carry;     
        if(res >= 10){
            carry = 1;
            res -= 10;
        }else{
            carry = 0;
        }
        ans = to_string(res) + ans;
        
        idx1--;
        idx2--;
    }
    if (carry) {
        ans = '1' + ans;
    }
    return ans;
}

string bigIntegerMul(string s1, string s2){
    string a=s2, b=s1;
    if(s1.length() >= s2.length()){
        a=s1;
        b=s2;
    }
    string ans = "0";
    int idx2 = b.length() - 1;
    int c = 0;
    for(int i = 0; i < b.length(); i++){
        string partialSum = "";
        
        for(int j = 0; j < c; j++){
            partialSum += '0';
        }  
        
        int digitB = idx2 >= 0 ? b[idx2] - '0' : 0; 
        if(idx2 < 0) break;
        
        if(digitB != 0){
            int idx1 = a.length() - 1;
            int carry = 0;
            for(int k = 0; k < a.length(); k++){
                int digitA = a[idx1] - '0';  
                
                int res = (digitA * digitB) + carry; 
                
                carry = res/10;
                int di = res%10;                

                partialSum = to_string(di) + partialSum;
                idx1--;
            }
            if (carry) {
                partialSum = to_string(carry) + partialSum;
            }
        }
        ans = bigIntegerSum(ans, partialSum);
        c++;
        idx2--;
    }
    
    return ans;
}

string solve(int n, int a){
    string ans = "0";
    vector<string> dp(n+1, "0");
    
    dp[0] = "1";
    
    for(int i = 1; i <= n; i++){
        dp[i] = bigIntegerMul(dp[i-1], to_string(a));
    }
    
    for(int i = 1; i <= n; i++){
        ans = bigIntegerSum(ans, bigIntegerMul(to_string(i), dp[i]));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    stringstream output;
    
    vector<vector<string>> ans;
    for(int i = 0; i <= 15; i++){
        vector<string> arrTemp(151, "0");
        
        vector<string> dp(151, "0");

        dp[0] = "1";
        
        for(int j = 1; j <= 150; j++){
            dp[j] = bigIntegerMul(dp[j-1], to_string(i));
        }
        
        arrTemp[0] = to_string(i);
        for(int j = 1; j < 150; j++){
            arrTemp[j] = bigIntegerSum(arrTemp[j-1], bigIntegerMul(to_string(j+1), dp[j+1]));
        }
        ans.push_back(arrTemp);
	}

	while(cin>>n>>a){
        if(n == 0 && a == 0){
            break;
        }
        output<< ans[a][n-1]<< '\n';
        
    }
    cout<<output.str();
    return 0;
}
