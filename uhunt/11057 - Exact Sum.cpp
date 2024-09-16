#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
	stringstream output;

	ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
	int n;
	while(cin>>n){
		vector<int> arr(n);
		for(int i = 0; i < n; i++) cin>>arr[i];
		sort(arr.begin(), arr.end());
		int objetive;
		cin>>objetive;
		
		int ans1 = 0;
		int ans2 = arr[n-1];
		
		
		for(int i = 0; i < n-1; i++){
			int s = arr[i];
			int res = binarySearch(arr, i+1, n-1, objetive - s);
			
			if(res != -1){
				int first = arr[i];
                int second = arr[res];
                if(abs(first - second) < abs(ans1 - ans2)){
					ans1 = first;
					ans2 = second;
				}				
			}
			
		}
		output<<"Peter should buy books whose prices are "<<ans1<<" and "<<ans2<<"."<<endl; 
		output<<endl;
	}
	cout<<output.str();
	return 0;
}
