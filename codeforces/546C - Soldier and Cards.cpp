#include <bits/stdc++.h>
using namespace std;
#define DBG_arr(arr) { \
    cout << #arr << " = ["; \
    for (size_t i = 0; i < arr.size(); ++i) { \
        cout << arr[i] << (i + 1 < arr.size() ? ", " : ""); \
    } \
    cout << "]" << endl; \
}

bool isRep(vector<pair<vector<int>, vector<int>>> &waos, vector<int> &v1, vector<int> &v2){
	//cout<<"IsRep called"<<endl;
	//DBG_arr(v1);
	//DBG_arr(v2);
	for(auto &p: waos){
		//DBG_arr(p.first);
		//DBG_arr(p.second);
		if(p.first == v1 && p.second == v2){
			return true;
		}
	}
	return false;
}

int main(){
	int n, k1, k2; cin>>n;	
	//solo simulacion!
	
	
	cin>>k1;
	vector<int> p1(k1);
	for(int i = 0; i < k1; i++) cin>>p1[k1 - i - 1];
	
	cin>>k2;
	
	vector<int> p2(k2);
	for(int i = 0; i < k2; i++) cin>>p2[k2 - i - 1];
	
	
	vector<pair<vector<int>, vector<int>>> waos;
	int count = 0;
	
	while(true){
		if(isRep(waos, p1, p2)){
			cout<<-1<<endl;
			break;
		}
		waos.push_back({p1, p2});
		int n1 = p1.back();
		int n2 = p2.back();
		p1.pop_back();
		p2.pop_back();
		//cout<<"n1: "<<n1<<endl;
		//cout<<"n2: "<<n2<<endl;
		if(n1 < n2){
			//primero se insertal el rival
			p2.insert(p2.begin(), n1);
			p2.insert(p2.begin(), n2);
		}else{
			p1.insert(p1.begin(), n2);
			p1.insert(p1.begin(), n1);	
		}
		count++;
		//DBG_arr(p1);
		//DBG_arr(p2);
		if(p2.size() == 0){
			cout<<count<<" "<<1<<endl;
			break;
		}
		
		if(p1.size() == 0){
			cout<<count<<" "<<2<<endl;
			break;
		}
	}
	
	
	
	return 0;
}