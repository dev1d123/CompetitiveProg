#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int, int>> waos;
int n;

int solve(int idx, set<int> st){
    if (idx == n) {
        return (st.size() == 9) ? 0 : INT_MIN;
    }
    int a = get<0>(waos[idx]);
    int b = get<1>(waos[idx]);
    int c = get<2>(waos[idx]);
    int score = get<3>(waos[idx]);
    bool newEl = (st.find(a) == st.end() && st.find(b) == st.end() && st.find(c) == st.end());
	int ignoreCurrent  = solve(idx + 1, st);
	
	if(newEl){
        set<int> newSet = st;
        newSet.insert(a);
        newSet.insert(b);
        newSet.insert(c);
        
        int includeCurrent = score + solve(idx + 1, newSet);
        
        return max(ignoreCurrent , includeCurrent);
	}else{
		return ignoreCurrent ;
	}
	
}


int main(){
	int c = 1;
	while(cin>>n){
		waos.clear();
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			int a, b, c, s;
			cin>>a>>b>>c>>s;
			waos.push_back({a,b,c,s});
		}
		set<int> st;
		int ans = solve(0, st);
		if(ans <= 0){
			ans = -1; 
		}
		cout<<"Case "<<c++<<": "<<ans<<endl;;
	}	
	
}