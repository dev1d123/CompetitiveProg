#include <bits/stdc++.h>
using namespace std;
stringstream output; 

void solve(string &a, string &b, string &c){
	//base 1...solo contiene 1's....la minima es 2
	if(stoi(a) == 0 && stoi(b) == 0 && stoi(c) == 0){
		cout<<2<<endl;
		return;
	}
	bool possible = true;
	int base = numeric_limits<int>::max();
	int baseTemp = 0;
	int carry = 0;  
	bool waos = false;
	int maxDigit=0;
	for(int i = 0; i < c.length(); i++){
	    int digitA = (i < a.length()) ? a[a.length() - i - 1] - '0' : 0;
    	int digitB = (i < b.length()) ? b[b.length() - i - 1] - '0' : 0;
		int digitC = c[c.length() - i - 1]-'0';
		
		maxDigit=max(maxDigit, max(digitA, max(digitB, digitC)));
		int ans = digitA + digitB + carry;
		carry = 0;
		//se calcula una menor base....
		if((ans - digitC) != 0 && !waos){ //se ha llevado un digito!!! 
			//si hay una nueva base si o si se ha llevado un nuevo grupo.
			//base definitiva!!
			base = ans - digitC;
			waos = true;
		}else{
			//comprobar al final
			baseTemp = max(baseTemp, ans+1);
		}
		
		//siempre verificar con la base actual!!!
		if(base != 1 && ans%base != digitC){
			possible = false;
		}else{
			carry = ans/base;
		}
	}

	if(!possible){
		output<<0<<endl;
	}else{
		if(base == numeric_limits<int>::max()){
			if(baseTemp > maxDigit){
				output<<baseTemp<<endl;
			}else{
				output<<0<<endl;
			}
		}else if(base == 1){
			if(a.length() + b.length() == c.length()){
				output<<1<<endl;
			}else{
				output<<0<<endl;

			}
		}else{
			if(base > maxDigit){
				output<<base<<endl;
			}else{
				output<<0<<endl;
			}
		}
	}
}
int main() {
    int t; cin>>t;
    cin.ignore(); 
    while(t--){
    	string input;
    	getline(cin, input);
    	stringstream ss(input);
    	string a,b,c,d;
    	
		ss>>a>>d>>b>>d>>c;    	

		solve(a,b,c);
	}
	cout<<output.str();
}