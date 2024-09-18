#include <bits/stdc++.h>
using namespace std;
int mex(set<int> &s){
	int m=1;
	while(s.count(m)){
		m++;
	}
	return m;
}
int main(){
	int n; cin>>n;
	set<int> waos;
	while(n--){
		int num; cin>>num;
		waos.insert(num);
	}
	cout<<mex(waos);
	return 0;
}