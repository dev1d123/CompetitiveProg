#include <bits/stdc++.h>
using namespace std;

vector<int> div(int n){
	vector<int> arr; 
	for(int i = 1; i * i <= n; i++){
		if(n%i == 0){
			arr.push_back(i);
			if(i != 1 && n/i != i){
				arr.push_back(n/i);
			}
		}
	}
	if(n > 1){
		arr.push_back(n);
	}
	return arr;
}

int lcm(int a, int b){
	return a / __gcd(a, b) * b;
}
int main(){
	int n;
	while(cin>>n){
		if(n == 0) break;
		vector<int> divi = div(n);
		sort(divi.begin(), divi.end());
		int ans = 0;
		for(int i = 0; i < divi.size(); i++){
			for(int j = 0; j < i; j++){
				if(lcm(divi[i], divi[j]) == n){
					ans ++;
				}
			}
		}		
		cout<<n<<" "<<ans + 1<<endl;
	}
	return 0;
}