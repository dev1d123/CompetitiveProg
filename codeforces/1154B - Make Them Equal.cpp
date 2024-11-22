#include <bits/stdc++.h>
using namespace std;

bool equal(vector<int> &a, vector<int> &b, vector<int> &c, int e){

	for(int i = 0; i < a.size(); i++){
		if(!(a[i] == e || b[i] == e || c[i] == e)){
			return false;
		}
	}
	
	return true;
}

int main(){
	int n; cin>>n;
	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	
	
	for(int i = 0; i <= 100; i++){
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		set<int> el;
		
		for(int j = 0; j < n; j++){
			a[j] = arr[j];
			b[j] = arr[j] - i;
			c[j] = arr[j] + i;

			el.insert(a[j]);
			el.insert(b[j]);
			el.insert(c[j]);
		}
		for(int e: el){
			if(equal(a, b, c, e)){
				cout<<i<<endl;
				return 0;
				
			}
		}
	}
	
	cout<<-1<<endl;
	
	
	return 0;
}