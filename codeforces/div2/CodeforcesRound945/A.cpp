#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c; cin>>a>>b>>c;
		int pair = 0;
		if(a%2 == 0) pair++;
		if(b%2 == 0) pair++;
		if(c%2 == 0) pair++;
		if(pair%2 == 0){
			cout<<-1<<endl;
			continue;
		}
		int draw = 0;
		int ab = 0;
		while(a >= 0 || b >= 0){
			int caso = 0;
			int A = a;
			int B = b;
			int C = c;
			int para = min(B,C);
			B-=para;
			C-=para;
			caso = para;
			para = min(A, max(B,C));
			caso += para;	
			caso += ab;
			
			draw = max(draw, caso);
			a--;
			b--;
			ab++;
			
			
			
		}
		cout<<draw<<endl;
	}
	
	
	return 0;
}



    