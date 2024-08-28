#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	stringstream output;
	bool wtf = false;
	while(cin>>n){
		if(n == 0){
			break;
		}else{
			if(wtf){
				output<<endl;
			}
			wtf = true;

		}
		bitset<32> bit(n);
		string bitStr = bit.to_string();
		string waos = bitStr.substr(bitStr.find('1'));
		int sum = 0;
		for(char c: waos){
			if(c == '1'){
				sum++;
			}
		}
		output<<"The parity of "<<waos<<" is "<<sum<<" (mod 2).";
	}
	cout<<output.str()<<endl;
	
	return 0;
}