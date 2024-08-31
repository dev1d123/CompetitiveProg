#include <bits/stdc++.h>
using namespace std;

int getNum(char c){
	if(isalpha(c)){
		return c - 'A' + 10;
	}
	return c-'0';
}
//easily to prove...factoring
int convert(string &num, int b) {
    int res = 0;
    for (char c : num) {
        res = res * b + getNum(c);
    }
    return res;
}

signed main(){
	string line;
	stringstream output;
	while(getline(cin, line)){
		/*
		if(line == "xd") {
			cout<<"Saliendo"<<endl;
			break;
		}
		*/
		stringstream ss(line);
		
		string x;
		string y;

		ss>>x>>y;
		
		//suppossing that x and y are always int o 32 bits
		
		int initialBase1 = 0;
		int initialBase2 = 0;
		for(char c: x){
			initialBase1 = max(initialBase1, getNum(c));
		}
		for(char c: y){
			initialBase2 = max(initialBase2, getNum(c));
		}
		
		if(x == "0" && y == "0"){
			output<<x<<" (base "<<2<<") = "<<y<<" (base "<<2<<")"<<endl;
			continue;
		}
		int a,b;
		bool ans = false;
		
		for(int i = initialBase1 + 1; i <= 36; i++){
			for(int j = initialBase2 + 1; j <= 36; j++){
			
				if(convert(x, i) == convert(y, j)){
					a = i, b = j;
					ans = true;
					break;
				}
			}
			if(ans) break;
		}
		
		if(ans){
			output<<x<<" (base "<<a<<") = "<<y<<" (base "<<b<<")"<<endl;
		}else{
			output<<x<<" is not equal to "<<y<<" in any base 2..36"<<endl;
		}
		
	}
	cout<<output.str();
	return 0;
}