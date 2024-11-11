#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string a, b; cin>>a>>b;
		
		int len = min(a.length(), b.length());
		
		bool equal = true;
		int fl = 0;
		
		for(int i = 0; i < len; i++){
			int n1 = a[i] - '0';
			int n2 = b[i] - '0';
            if (equal && n1 != n2) {
                if (n1 < n2) {
                    fl = 1;
                }else if(n1 > n2){
                	fl = 2;
				}
                equal = false;
                continue;
            }
 
            if (!equal) {
            	if(fl == 1){
                    a[i] = max(n1, n2) + '0'; 
                	b[i] = min(n1, n2) + '0';
 
				}else if(fl == 2){
					b[i] = max(n1, n2) + '0';
                	a[i] = min(n1, n2) + '0';
				}
 
            }
		}
		cout<<a<<endl;
		cout<<b<<endl;
	}
	
	
	return 0;	
}