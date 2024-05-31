#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int n; cin>>n;

    int maxLength = n*2 + 1;

    int c = n;
    int spaces = n*2;
    int sc = spaces;
    for(int i = 1; i <=maxLength; i++){
    	int num = maxLength - abs(c*2);
		c--;
		int len = (num-1)/2;
		int c2 = len;
		for(int x = 0; x < abs(sc); x++){
			cout<<" ";
		}		
		for(int j = 1; j <= num; j++){			
			cout<<len - abs(c2);
			if(j != num){
				cout<<" ";
			}
			c2--;
		}
		if(i != maxLength){
			cout<<endl;
		}
		sc-=2;
    }


    return 0;
}

