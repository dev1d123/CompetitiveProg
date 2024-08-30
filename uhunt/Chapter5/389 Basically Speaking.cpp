#include <bits/stdc++.h>
#define int long long
using namespace std;

int getNum(char ch){
	if(isalpha(ch)){
		return ch - 'A' + 10;
	}
	return ch-'0';	
}
int toBase10(string &num, int base){
	int ans=0;
	int c = num.length() - 1;
	for(int i = 0; i < num.length(); i++){
		ans += getNum(num[c])*pow(base, i);
		c--;
	}
	return ans;	
}

string toBaseN(int num, int base){
	string ans = "";
	string numerals = "0123456789ABCDEF";
	while(num > 0){
		int res = num%base;
		ans=numerals[res]+ans;
		num/=base;
	}
	return ans;
}
signed main(){
	string s;
	while(getline(cin, s)){
		stringstream ss(s);
		string n1;
		int b1;
		int b2;
		ss>>n1>>b1>>b2;
		string resultado = toBaseN(toBase10(n1, b1), b2);
		if(resultado.length() > 7){
			cout<<"  ERROR"<<endl;
		}else{
			if(resultado.length() == 0){
				cout<<"      0"<<endl;
			}else{
				for(int i = 0; i <  7 - resultado.length(); i++){
					cout<<" ";
				}
				cout<<resultado<<endl;
			}
		}
	}
	return 0;
}