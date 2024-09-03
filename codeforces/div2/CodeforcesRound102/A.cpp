#include <bits/stdc++.h>
using namespace std;
int main(){
	int r1,r2,c1,c2,d1,d2;
	cin>>r1>>r2>>c1>>c2>>d1>>d2;
	
	bool ans = false;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(j==i) continue;
			for(int k = 1; k <= 9; k++){
				if(k==j || k == i) continue;
				for(int m = 1; m < 9; m++){
					if(m==k || m == j || m == i){
						continue;
					}
					if(i+j == r1 && k+m==r2 && i+k==c1 && j+m==c2 && i+m==d1 && j+k == d2){
						ans = true;
						cout<<i<<" "<<j<<endl;
						cout<<k<<" "<<m<<endl;
					}
				}
			}
		}
	}
	if(!ans) cout<<"-1"<<endl;
	return 0;
}