#include <bits/stdc++.h>
using namespace std;


int main(){
	string n;
	stringstream output;
	while(cin>>n){
		if(n == "0"){
			break;
		}
		int num = 0;
		int c = 0;
		for(int i = n.length() - 1; i >= 0; i--){
			num += (n[i]-'0')*(pow(2, c+1)-1);
			c++;
		}

		output<<num<<endl;
	}
	cout<<output.str();
	
	return 0;
}