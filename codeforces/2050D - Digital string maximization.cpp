#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		for(int i = 1; i < s.length(); i++){
			int j = i;
			//cada numero puede desplazarse como maximo 8 posiciones -> O(8*n)
			while(j >= 1 && s[j] - 1 > s[j-1]){
				s[j]--;
				swap(s[j], s[j-1]);
				j--;
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}