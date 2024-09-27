#include <bits/stdc++.h>
#define ll long long
using namespace std;
void put(string &s, char c, int pos){
	int count = 0;
	for(int i = 0; s.length(); i++){
		if(s[i] != '*') continue;
		if(count == pos){
			s[i] = c;
			return;
		}
		count++;
	}
}
int main(){
	vector<ll> fact(21);
	fact[0] = fact[1] = 1;
	for(ll i = 2; i <= 20; i++){
		fact[i] = i*fact[i-1];
	}
	int t; cin>>t;
	int c = 1;
	while(t--){
		string s; ll n;
		cin>>s>>n;
		vector<int> relPos(s.length());
		int div = s.length() - 1;
		string ans = "";
		for(ll i = 0; i < s.length(); i++){
			ans += '*';
		}
		for(ll i = 0; i < s.length(); i++){
			int pos;
			if(n%fact[div] == 0){
				pos = n/fact[div];
				pos--;
			}else{
				pos = n/fact[div];
			}
			//modificar el sig
			n = n - pos*fact[div];
			
			/*
			cout<<"La posicion de "<<s[i]<<" es: "<<endl;
			cout<<pos<<endl;
			*/
			put(ans, s[i], pos);
			div--;
		}
		cout<<"Case "<<c++<<": "<<ans<<endl;
	}
	return 0;
}