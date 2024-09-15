#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s = "";
		string v = "aeiou";
		if(n <= 5){
			for (int i = 0; i < n; ++i) {
            	s += v[i % 5]; 
        	}
		}else{
			int num = n/5;
			string a,e,i,o,u;
			for(int x = 0; x < num; x++) a += "a";
			for(int x = 0; x < num; x++) e += "e";
			for(int x = 0; x < num; x++) i += "i";
			for(int x = 0; x < num; x++) o += "o";
			for(int x = 0; x < num; x++) u += "u";
			
			if(n%5 == 1) a += "a";	
			if(n%5 == 2) {
				a += "a";
				e += "e";	
			}
			if(n%5 == 3){
				a += "a";
				e += "e";
				i += "i";	
			}
			if(n%5 == 4){
				a += "a";
				e += "e";
				i += "i";
				 o += "o";	
			}
			s = a+e+i+o+u;
		}

        cout<<s<<endl;
	}
	return 0;
}