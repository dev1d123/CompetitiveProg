#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll binarySearchClosest(vector<ll> &arr, ll target){
	ll left = 0;
	ll right = arr.size() - 1;
	if(target < arr[0]){
		return -1;
	}
	if(target > arr[right]){
		return right;
	}
	
	while(left < right){
		ll mid = left + (right - left) / 2;
		if(arr[mid] == target){
			return mid;
		}else if(arr[mid] < target){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	return right;
}
int main(){	
	set<ll> st;
    for (ll i = 1; ; ++i) {
        ll i_squared = pow(i, 2);
        if (i_squared > 1000000000001) break;

        for (ll j = 0; ; ++j) {
            ll pow2_j = pow(2, j);
            ll num = i_squared * pow2_j;
            if (num > 1000000000001) break;
            st.insert(num);
        }
    }
    vector<ll> arr;
    ll t = 0;
    for(ll num: st){
    	arr.push_back(num);
	}

    ll n;
    while(cin>>n){
    	if(n == 0) break;
    	ll index = binarySearchClosest(arr, n);
    	if(arr[index] > n){
    		index--;
		}
		cout<<n-index-1<<endl;
	}
}