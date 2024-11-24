#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		cin>>arr[i];	
	}
	
	//find the number of descendings segments, it must be 1!!!
	int q = 0;
	int start = 0;
	int end = 0;

	for(int i = 0; i < n - 1; i++){
		if(arr[i] > arr[i + 1]){
			if(q != 0){
				cout<<"no"<<endl;
				return 0;
			}
			start = i;
			while(i < n - 1 && arr[i] > arr[i + 1]){
				i++;
				end=i;
			}
			q++;
		}
	}

	int mi = INT_MAX;
	int ma = 0;
	for(int i = start; i <= end ; i++){
		mi = min(mi, arr[i]);
		ma = max(ma, arr[i]);
	}	
	for(int i = 0; i < start; i++){
		if(arr[i] > mi){
			cout<<"no"<<endl;
			return 0;
		}
	}
	for(int i = end + 1; i < n; i++){
		if(arr[i] < ma){
			cout<<"no"<<endl;
			return 0;
		}
	}

	
	cout<<"yes"<<endl;
	cout<<start + 1<<" "<<end + 1<<endl;
	return 0;
}
//3 2 1 4 5 6 19 18 17