#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >>n;
	vector<pair<int, int>> arr(2*n);
	for(int i = 0; i < 2*n; i++){
		int num; cin >>num;
		arr[i] = {num, i};
	}
	sort(arr.begin(), arr.end());
	for(int i = 1; i < 2 * n; i += 2) {
	    if(arr[i].first != arr[i - 1].first) {
	        cout << -1 << endl;
	        return 0;
	    }
	}
	for(int i = 1; i < 2 * n; i += 2) {
        cout << arr[i].second + 1 << ' ' << arr[i - 1].second + 1 << endl;
    }
	return 0;
}