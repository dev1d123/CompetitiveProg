#include <bits/stdc++.h>
#define int long long
using namespace std;
void simplify(int &numerator, int &denominator) {
    int divisor = __gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

signed main(){
	int t; cin>>t;
	int c = 1;
	stringstream output;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		int prod = 1;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			prod *= arr[i];
		}
		int sum = 0;
		for(int num: arr){
			sum+=prod/num;
		}	
		int numerator = prod*n;
		int denominator = sum;
		simplify(numerator, denominator);
		output<<"Case "<<c<<": "<<numerator<<"/"<<denominator<<endl;
		c++;
	}
	cout<<output.str();
	
	
	return 0;
}
