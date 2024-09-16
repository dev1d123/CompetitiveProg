#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		vector<int>a(3);
		cin>>a[0]>>a[1]>>a[2];
		sort(a.begin(), a.end());
		
		for(int i = 0; i < 5; i++){
			int p1 = (a[0] + 1) * a[1] * a[2];	
			int p2 = a[0] * (a[1] + 1) * a[2];
			int p3 = a[0] * a[1] * (a[2] + 1);
			
			if(p1 >= p2 && p1 >= p3) a[0]++;
			else if(p2 >= p1 && p2 >= p3) a[1]++;
			else if(p3 >= p2 && p3 >= p1) a[2]++;
		}
		cout<<a[0]*a[1]*a[2]<<endl;
	}
}