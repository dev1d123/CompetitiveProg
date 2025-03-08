#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            int x; cin>>x;
            arr[i] = x;
        }
        
        sort(arr.begin(), arr.end());
        int idx = 1;
        int ans = 0;
        if(arr[0] > 1){
            ans += arr[0] - 1;
        }
        int act = 1;
        while(idx < n){
            int elem = arr[idx];
            while(idx < n && elem == arr[idx]){
                act = min(elem, act+1);
                ans += abs(act - arr[idx]);
                idx++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}