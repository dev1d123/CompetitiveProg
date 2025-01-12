#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> mp1;
    map<int, int> mp2;

    for(int i = 0; i < n; i++){
      cin>>a[i];
      mp1[a[i]]++;
    }
    for(int i = 0; i < n; i++){
      cin>>b[i]; 
      mp2[b[i]]++;
    }
    for(auto p: mp1){
      if(mp2[p.first] != 0){
        int del = min(mp1[p.first], mp2[p.first]);
        mp1[p.first] -= del;
        mp2[p.first] -= del;
      }
    }
    for(auto p: mp2){
      if(mp1[p.first] != 0){
        int del = min(mp1[p.first], mp2[p.first]);
        mp1[p.first] -= del;
        mp2[p.first] -= del;
      }
    }
    int ans = 0;
    for(auto p:mp1){
      if(p.first >= 10){
        int rep = p.second;
        while(rep--){
          int lo = to_string(p.first).length();
          mp1[lo]++;
          ans++;
        }
        mp1[p.first] = 0;
      }
      
    }
    for(auto p: mp2){
      if(p.first >= 10){
        int rep = p.second;
        while(rep--){
          int lo = to_string(p.first).length();
          mp2[lo]++;
          ans++;
        }
        mp2[p.first] = 0;
      }
    }
    set<int> st;
    for(auto p: mp1){
      st.insert(p.first);
    }
    for(auto p: mp2){
      st.insert(p.first);
    }

    for(int k: st){
      if(k == 1) continue;
      int del = min(mp1[k], mp2[k]);
      int con = max(mp1[k], mp2[k]);
      ans += con-del;
    }
    cout<<ans<<endl;


  }


  return 0;
}