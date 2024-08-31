#include <bits/stdc++.h>
#define int long long

using namespace std;
void simp(int &a, int &b){
	int gcd = __gcd(a,b);
	a/=gcd;
	b/=gcd;
}
signed main(){
	int n;
	string num;
	stringstream output;
	int c = 1;
	while(cin>>n){
		if(n == -1){
			break;
		}
		cin>>num;
		if(n == 0){		
			string periodic = num.substr(2);
			string den = "1";
			for(int i = 0; i < periodic.length(); i++){
				den+="0";
			}
			int numerator = stol(periodic);
			int denominator = stol(den);
			simp(numerator, denominator);
			output<<"Case "<<c<<": "<<numerator<<"/"<<denominator<<endl;
		}else if(n == num.length() - 2 || n == 0){
			string periodic = num.substr(2);
			string den = "";
			for(int i = 0; i < n; i++){
				den+="9";
			}
			int numerator = stol(periodic);
			int denominator = stol(den);			
			simp(numerator, denominator);
			output<<"Case "<<c<<": "<<numerator<<"/"<<denominator<<endl;

		}else{
			string rest = num.substr(2, num.length() - 2 - n);
			string periodic = num.substr(rest.length() + 2);
			string allNum = num.substr(2);

			string den = "";
			for(int i = 0; i < periodic.length(); i++){
				den+="9";
			}
			for(int i = 0; i < rest.length(); i++){
				den+="0";
			}
			int numerator = stol(allNum) - stol(rest);
			int denominator = stol(den);
			simp(numerator, denominator);
			output<<"Case "<<c<<": "<<numerator<<"/"<<denominator<<endl;
		}
		//num -> fractional form
		c++;
	}
	cout<<output.str();
}