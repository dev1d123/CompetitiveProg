#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(auto &it: arr) cin>>it;
    for(int i = 0; i < n; i++){
        if(arr[i]%2==0) arr[i]--;
    }
    for(int elem: arr){
        cout<<elem<<" ";
    }


    return 0;
}