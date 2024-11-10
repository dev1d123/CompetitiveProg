#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> weight;
vector<int> load;

vector<vector<int>> memo;

int solve(int idx, int usedWeight){
	if(idx == n){
		return 0;
	}
	int &ans = memo[idx][usedWeight]; 

	if (ans != -1) {
        return ans;
    }
	if(weight[idx] > usedWeight){
		return ans = solve(idx + 1, usedWeight);
	}
	return ans = max(solve(idx + 1, usedWeight), 1 + solve(idx + 1, min(usedWeight - weight[idx], load[idx])) );
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n){
		if(n == 0) break;
		weight.assign(n, 0);
		load.assign(n, 0);
		int highestLoad = 0;
		for(int i = 0; i < n; i++){
			cin>>weight[i];
			cin>>load[i];
			highestLoad = max(highestLoad, load[i]);

		}
		
        memo.assign(n, vector<int>(highestLoad + 1, -1));
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans = max(ans, 1 + solve(i + 1, load[i]));
		}
        cout<<ans<<endl;
	}
	return 0;	
}