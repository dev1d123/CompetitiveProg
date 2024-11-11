#include <bits/stdc++.h>
using namespace std;
int main(){
	map<int, int> w;
	int v; 
	cin>>v; w[v]++;
	cin>>v; w[v]++;
	cin>>v; w[v]++;
	if(w[5] == 2 && w[7] == 1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}