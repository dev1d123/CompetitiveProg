#include <bits/stdc++.h>
using namespace std;

string prodString(const string& a, const string& b) {
    bool negative = (a[0] == '-' ^ b[0] == '-');
    string num1 = (a[0] == '-') ? a.substr(1) : a;
    string num2 = (b[0] == '-') ? b.substr(1) : b;
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    string prod;
    for (int num : result) {
        if (!(prod.empty() && num == 0)) prod += to_string(num); 
    }
    if (prod.empty()) prod = "0"; 
    if (negative && prod != "0") prod = "-" + prod; 
    return prod;
}

string maxString(const string& a, const string& b) {
    bool isNegativeA = (a[0] == '-');
    bool isNegativeB = (b[0] == '-');

    if (isNegativeA && !isNegativeB) return b;
    if (!isNegativeA && isNegativeB) return a;

    if (isNegativeA && isNegativeB) {
        if (a.size() != b.size()) return (a.size() > b.size()) ? b : a;
        return (a > b) ? b : a;
    } else {
        if (a.size() != b.size()) return (a.size() > b.size()) ? a : b;
        return (a > b) ? a : b;
    }
}

string minString(const string& a, const string& b) {
    bool isNegativeA = (a[0] == '-');
    bool isNegativeB = (b[0] == '-');

    if (isNegativeA && !isNegativeB) return a;
    if (!isNegativeA && isNegativeB) return b;

    if (isNegativeA && isNegativeB) {
        if (a.size() != b.size()) return (a.size() > b.size()) ? a : b;
        return (a > b) ? a : b;
    } else {
        if (a.size() != b.size()) return (a.size() > b.size()) ? b : a;
        return (a > b) ? b : a;
    }
}
int main(){
	string s;
	while(getline(cin, s)){
		stringstream ss(s);
		string temp;
		vector<string> arr;
		while(ss>>temp){
			if(temp != "-999999"){
				arr.push_back(temp);	
			}
		}
		vector<string> dp1(arr.size(), "0"); //maximo producto posible, considerando el elemento i
		vector<string> dp2(arr.size(), "0"); //minimo producto posible, considerando el elemento i
		
		dp1[0] = arr[0];
		dp2[0] = arr[0];
		string ans = arr[0];
		
		for(int i = 1; i < arr.size(); i++){	
			string prod1 = prodString(arr[i], dp1[i-1]);
			string prod2 = prodString(arr[i], dp2[i-1]);
			
			dp1[i] = maxString(arr[i], maxString(prod1, prod2));
			dp2[i] = minString(arr[i], minString(prod1, prod2)); 
			
			ans = maxString(ans, dp1[i]);
		}
		cout<<ans<<endl;
		arr.clear(); 
	}
	return 0;
}