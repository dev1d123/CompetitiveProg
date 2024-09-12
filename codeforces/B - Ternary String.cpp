#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		vector<int> arr1;
		vector<int> arr2;
		
		for(int i = 0; i < s.length(); i++){
			int num = s[i] - '0';
			arr1.push_back(num);
			int c = 0;
			while(i < s.length() && num == s[i] - '0'){
				c++;
				i++;
			}
			arr2.push_back(c);
			i--;
		} 
		int ans = INT_MAX;
		if(arr1.size() < 3){
			cout<<0<<endl;
			continue;
		}
		
		for(int i = 0; i <= arr1.size() - 3; i++){
			vector<int> waos = {arr1[i], arr1[i+1], arr1[i+2]};
			sort(waos.begin(), waos.end());
            if (waos[0] == 1 && waos[1] == 2 && waos[2] == 3) {
                ans = min(ans, 2 + arr2[i+1]); 
            }
		}
        if (ans == INT_MAX) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
	}
	
	return 0;
}