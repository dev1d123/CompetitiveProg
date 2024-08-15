#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,q; cin>>n>>q;
		string s1;
		string s2;
		cin>>s1>>s2;
		
		//precalculate with arr 2x2.
		vector<vector<int>> dp1(n + 1, vector<int>(26, 0));
        vector<vector<int>> dp2(n + 1, vector<int>(26, 0));
		for (int i = 0; i < n; i++) {
			
			//mantener el conteo de caracteres anteriores, prefix
            for (int j = 0; j < 26; j++) {
                dp1[i + 1][j] = dp1[i][j];
                dp2[i + 1][j] = dp2[i][j];
            }
            //asignando
            dp1[i + 1][s1[i] - 'a']++;
            dp2[i + 1][s2[i] - 'a']++;
        }
		
		while(q--){
			int l, r; 
			cin>>l>>r;
			
			int ans = 0;
            for (int i = 0; i < 26; i++) {
            	
				int count1 = dp1[r][i] - dp1[l - 1][i];
                int count2 = dp2[r][i] - dp2[l - 1][i];
            	
                if (count1 > count2) {
                    ans += count1 - count2;
                }
            }
			cout<<ans<<endl;
		}
	}
	return 0;
}