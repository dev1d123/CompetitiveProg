#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(auto &it: arr) cin>>it;
        sort(arr.begin(), arr.end());
        if(n == 1){
            cout<<1<<endl;
        }else{
            int ans = 1;
            int diff = INT_MAX;
            for(int i = 1; i < n; i++){
                diff = min(diff, abs(arr[i] - arr[i-1]));
                if(diff >= arr[i]){
                    ans++;
                }else{
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    

    return 0;
}