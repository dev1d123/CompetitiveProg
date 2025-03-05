#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(auto &it: arr) cin>>it;
        int ans = 0;
        for(int i = n-2; i >= 0; i--){
            int elem = arr[i+1];
            if(elem == 0){
                ans = -1;
                break;
            }
            while(arr[i] >= elem){
                arr[i]/=2;
                ans++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}