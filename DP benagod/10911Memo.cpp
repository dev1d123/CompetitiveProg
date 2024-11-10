#include <bits/stdc++.h>
using namespace std;
double calcularDistancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double solve(int mask, vector<vector<double>> &distances, vector<double> &dp, int n){
	if(mask == (1<<n) - 1) return 0; 
	
    if(dp[mask] != -1.0) return dp[mask];
	double minDist = DBL_MAX;
    int p1 = -1;
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i))) {
            p1 = i;
            break;
        }
    }
    
	for(int p2 = p1 + 1; p2 < n; p2++) {
        if(!(mask & (1 << p2))) {
            double newDist = distances[p1][p2] + solve(mask | (1 << p1) | (1 << p2), distances, dp, n);
            minDist = min(minDist, newDist);
        }
    }
    
    return dp[mask] = minDist;
}

int main(){
	int n; 
	stringstream output;
	int c = 1;
	while(cin>>n){
		if(n == 0) break;
		n*=2;
		vector<string> tr(n);
		vector<pair<int, int>> axis(n);
		
		vector<vector<double>> distances(n*n, vector<double>(n*n, 0));
		
		for(int i = 0; i < n; i++){
			cin>>tr[i];
			int x, y; cin>>x>>y;
			axis[i] = {x, y};	
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				distances[i][j] = calcularDistancia(axis[i].first, axis[i].second, axis[j].first, axis[j].second);
			}
		}
	    vector<double> dp(1 << n, -1.0);
	    double minDistance = solve(0, distances, dp, n);
	
	    output<< fixed << setprecision(2);
	    output<<"Case "<<c++<<": "<< minDistance << endl;

	}
	cout<<output.str();
	
	return 0;
}