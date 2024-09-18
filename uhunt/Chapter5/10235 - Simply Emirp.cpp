#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 1000000;
	vector<int> pr(n + 1, 1);
	pr[0] = 0;
	pr[1] = 0;
	for(int i = 0; i * i <= n; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= n; j+=i){
				pr[j] = 0;
			}
		}
	}
	stringstream output;
	int num;
	while(cin>>num){
		if(pr[num] == 0){
			output<<num<<" is not prime."<<endl;
		}else{
			string rev = to_string(num);
			reverse(rev.begin(), rev.end());
			//f****** palindromes
			if(rev == to_string(num)){
				output<<num<<" is prime."<<endl;
				continue;
			}
			int r = stoi(rev);
			if(pr[r] == 0){
				output<<num<<" is prime."<<endl;
			}else{
				output<<num<<" is emirp."<<endl;
			}
		}
	}
	cout<<output.str();
	return 0;
}

