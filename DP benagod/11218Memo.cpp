#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int, int>> waos;
int n;
vector<vector<int>> memo;

int solve(int idx, int mask){
    if (idx == n) {
        return (__builtin_popcount(mask) == 9	) ? 0 : INT_MIN;
    }
    
    if(memo[idx][mask] != -1){
    	return memo[idx][mask];
	}
    
    int a = get<0>(waos[idx]) - 1;
    int b = get<1>(waos[idx]) - 1;
    int c = get<2>(waos[idx]) - 1;
    int score = get<3>(waos[idx]);
    
    bool newEl = ((mask & (1 << a)) == 0 && (mask & (1 << b)) == 0 && (mask & (1 << c)) == 0);
	int ignoreCurrent  = solve(idx + 1, mask);
	int includeCurrent = INT_MIN;
	if(newEl){
		int newMask = mask | (1 << a) | (1 << b) | (1 << c);
        includeCurrent = score + solve(idx + 1, newMask);
	}
    return memo[idx][mask] = max(ignoreCurrent, includeCurrent);	
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
		memo.assign(n, vector<int>(1 << 9, -1));
		set<int> st;
		int ans = solve(0, 0);
		if(ans <= 0){
			ans = -1; 
		}
		cout<<"Case "<<c++<<": "<<ans<<endl;;
	}	
	
}